// 휴게소 세우기
// 1. 이분 탐색 사용
// 2. 전 후 휴게소 거리를 구해야하기 때문에, 첫 지점과 끝 지점 restArea에 push
// 3. 휴게소를 더 지어야 하면 mid 값 더 크게
// 4. 덜 지어야 하면 mid 값 더 작게

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, L, input;
vector<int> restArea;

bool buildRestArea(int mid){
    int cntM = 0;

    for(int i=1; i<restArea.size(); i++){
        if(restArea[i] - restArea[i-1] > mid){
            cntM += (restArea[i] - restArea[i-1] - 1) / mid;
        }
    }

    return (cntM > M);
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> L;
    restArea.push_back(0);
    restArea.push_back(L);
    for(int i=0; i<N; i++){
        cin >> input;
        restArea.push_back(input);
    }
    sort(restArea.begin(), restArea.end());

    int left = 0;
    int right = L;

    while (left <= right){
        int mid = (left + right) / 2;

        if(buildRestArea(mid)){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    cout << left;
    return 0;
}