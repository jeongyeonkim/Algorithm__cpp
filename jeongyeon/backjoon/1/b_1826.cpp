// 연료 채우기
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<pair <int,int> > arr;
priority_queue<int> Q;
int N, L, P, cnt, i;

// 주유소를 거리순으로 오름차순 정렬.
// 현재 있는 연료로 갈 수 있는 주유소 중에 최대 채울 수 있는 주유소를 감.

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }
    cin >> L >> P;
    // 초기 연료로 갈 수 있는 거리 뺌.
    L -= P;

    sort(arr.begin(), arr.end());
    // 연료가 가야할 거리보다 커지면 while문 끝.
    while(L > 0){
        // for문 돌리면 메모리 초과.
        // for(int i=0; i<N; i++){
        //     if(arr[i].first <= P){
        //         Q.push(arr[i].second);
        //     }
        // }
        while (arr[i].first <= P){
            if(arr[i].first <= P){
                if (i == N)break;
                Q.push(arr[i].second);
                i++;
            }
        }
        // 모든 주유소를 들려도 마을 도착 못할 경우.
        if(Q.size() == 0){ break; }
        cnt++;
        P += Q.top();
        L -= Q.top();
        Q.pop();
    }

    if(L > 0){ cout << -1; }
    else{ cout << cnt; }
}
