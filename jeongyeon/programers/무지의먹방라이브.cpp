#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair <int, int> > food;
long long beforeFood, sum;

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int foodSize = food_times.size();
    for(int i=0; i<foodSize; i++){
        sum += food_times[i];
        food.push_back(make_pair(food_times[i], i+1));
    }
    if(sum <= k){ return -1; } // 총 음식 합보다 k가 큰경우 -1 리턴
    sort(food.begin(), food.end());

    for(int pos=0; pos<foodSize; pos++){
        if(food[pos].first == 0){ continue; } // 먹을 음식이 없는 경우 continue

        long long frontFood = (food[pos].first - beforeFood) * (foodSize-pos);
        if(k - frontFood >= 0){
            k -= frontFood;
            beforeFood = food[pos].first;
        }else{
            k %= (foodSize-pos);
            sort(food.begin() + pos, food.end(), cmp);
            answer = food[k + pos].second;
            break;
        }
    }
    
    return answer;
}


// 이분탐색 방법
#include <string>
#include <vector>
using namespace std;
long long check(int mid, vector<int> &food_times) {
	long long sum = 0;
	for (int i = 0; i < food_times.size(); i++) {
		if (food_times[i] > mid) sum += (long long) mid;
		else sum += (long long) food_times[i];
	}
	return sum;
}
int solution(vector<int> food_times, long long k) {
	int m = 100000000;
	int M = 0;
	for (int i = 0; i < food_times.size(); i++) {
		m = min(m, food_times[i]);
		M = max(M, food_times[i]);
	}
	
	int left = 1;
	int right = M;
	int ans = 0;
	long long kk = k;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long val = check(mid, food_times);
		if (val > k) {
			right = mid - 1;
		}
		else if(val < k) {
			ans = mid;
			kk = k - val;
			left = mid + 1;
		}
		else {
			ans = mid;
			kk = k - val;
			break;
		}
	}
	int answer = 1;
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < food_times.size(); i++) {
		if (food_times[i] - ans > 0) {
			flag = true;
			if (cnt == kk) {
				answer = i + 1;
				break;
			}
			cnt++;
		}
	}
	
	if (flag) return answer;
	else return -1;
}