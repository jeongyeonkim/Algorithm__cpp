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