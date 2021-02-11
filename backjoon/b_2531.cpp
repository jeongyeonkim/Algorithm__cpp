// 회전 초밥
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, d, k, c, result, idx;
vector<int> arr;
int exist[3001];
int sushi_cnt;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> d >> k >> c;
    int input;
    int temp = 0;
    for(int i=0; i<N; i++){
        cin >> input;
        arr.push_back(input);
        if(temp < k){
            exist[input]++;
            if(exist[input] == 1){ sushi_cnt++; }
            temp++;
        }
    }
    exist[c]++;
    if(exist[c] == 1){ sushi_cnt++; }
    result = sushi_cnt;

    for(int i=1; i<N; i++){
        idx = (i + k - 1) % N;
        exist[arr[idx]]++;
        if(exist[arr[idx]] == 1){ sushi_cnt++; }

        exist[arr[i - 1]]--; 
        if(exist[arr[i - 1]] <= 0){ sushi_cnt--; }

        result = max(result, sushi_cnt);
    }

    cout << result;
    return 0;
}



// set -> 초밥 종류 중복 제거
// exit -> 현재 있는 구간에 있는 각각의 초밥 수 카운트
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int N, d, k, c, result;
vector<int> arr;
set<int> sushi;
int exist[3001];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> d >> k >> c;
    int input;
    for(int i=0; i<N; i++){
        cin >> input;
        arr.push_back(input);
    }

    sushi.insert(c);
    exist[c]++; 
    for(int i=0; i<k; i++){
        exist[arr[i]]++;
        sushi.insert(arr[i]);
    }

    for(int i=1; i<N; ++i){
        int idx = (i + k - 1) % N;
        sushi.insert(arr[idx]);
        exist[arr[idx]]++;

        exist[arr[i - 1]]--;
        if(exist[arr[i - 1]] <= 0){ sushi.erase(arr[i - 1]); }

        result = max(result, (int)sushi.size());
    }

    cout << result;
    return 0;   
}