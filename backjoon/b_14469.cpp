// 소가 길을 건너간 이유3
// 1. 도착 시간이 빠른 순서대로 정렬.
// 2. 우선순위 큐 이용 >> 도착한 소들 중에 검문 시간이 작은 소부터 처리.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, input1, input2, result_time;
vector<pair <int, int>> cow;
priority_queue<int> que;

bool cmp(const pair<int, int> a, const pair<int, int> b){
    if(a.first < b.first){ return true; }
    if(a.first == b.first){
        if(a.second < b.second){ return true; }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> input1 >> input2;
        cow.push_back(make_pair(input1, input2));
    }
    sort(cow.begin(), cow.end(), cmp);
    int idx = 0;

    while (idx <= N) {
        if(cow[idx].first <= result_time){
            que.push(cow[idx++].second);
        }

        if(!que.empty()){
            result_time += que.top();
            que.pop();
            continue;
        }
        result_time++;
    }
    
    cout << result_time;
    return 0;
}