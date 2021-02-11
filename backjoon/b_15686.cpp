// 치킨 배달
// 선택하는 치킨 집 조합 -> DFS
// 최대 M개라 하였지만 M개 가게 다 설치한 경우가 최소 도시의 치킨거리 값이 나옴
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, result = 1e9;
int arr[51][51];
vector<pair <int, int> > store, home;
int selected[14];

int Distance(int r1, int c1, int r2, int c2){ // 거리 구하는 함수
    return abs(r1-r2) + abs(c1-c2);
}

void sol(){
    int sum = 0, d;
    for(int i=0; i<home.size(); i++){
        if(sum > result){ return; } // 지금까지 구한 도시의 치킨거리의 값 이전에 구한 도시의 치킨거리 값보다 클 경우 더이상 계산할 필요
        d = 1e9;
        for(int j=0; j<M; j++){ // 해당 집에서 최단 거리 치킨집 구하기
            d = min(d, Distance(store[selected[j]].first, store[selected[j]].second, home[i].first, home[i].second));
        }
        sum += d;
    }
    result = min(result, sum);
}

void select(int idx, int cnt){ // m개 가게 조합
    if(cnt >= M){
        sol();
        return;
    }

    for(int i=idx+1; i<store.size(); i++){
        selected[cnt] = i;
        select(i, cnt + 1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){ store.push_back(make_pair(i, j)); } // 가게 위치 
            else if(arr[i][j] == 1){ home.push_back(make_pair(i, j)); } // 집 위치
        }
    }
    select(-1, 0);
    cout << result;
    return 0;
}