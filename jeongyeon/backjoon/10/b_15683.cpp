// 감시
#include <iostream>
#include <vector>
using namespace std;
int N, M, result;
int arr[9][9];
vector<pair <int, int> > camera[5];

int cntBlind(){
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 0){ cnt++; } 
        }
    }
    return cnt;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            // 5번 감시 카메라는 구역이 변동되지 않기 때문에 입력때부터 사각지대 제거.
            if(arr[i][j] == 5){
                for(int z=0; z<N; z++){ if(arr[z][j] == 0) arr[z][j] = -1; }
                for(int z=0; z<N; z++){ if(arr[i][z] == 0) arr[i][z] = -1; }
            }
            if(arr[i][j] >= 1 && arr[i][j] <= 4){ camera[arr[i][j]].push_back(make_pair(i, j)); }
        }
    }

    

    cout << result;
    return 0;
}