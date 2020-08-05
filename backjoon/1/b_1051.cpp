// 숫자 정사각형
// 브루트 포스
// 1. 모든 좌표에서 정사각형 만들어보기 >> 3중 for문으로 처리
// 2. 최대 정사각형은 N, M 중 작은 수가 최대
#include <iostream>
#include <string>
using namespace std;
int N, M, result = 1;
string str;
int arr[51][51];


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int minLength = min(N, M);
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<M; j++){ arr[i][j] = str[j] - '0'; }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=1; k<=minLength; k++){
                if(i + k < N && j + k < M){
                    if(arr[i+k][j] == arr[i][j] && arr[i+k][j+k] == arr[i][j] && arr[i][j+k] == arr[i][j]){
                        result = max(result, k + 1);
                    }
                }
            }
        }
    }

    cout << result * result;
    return 0;
}