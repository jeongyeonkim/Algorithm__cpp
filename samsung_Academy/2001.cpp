// 파리 퇴치
// 파리 퇴치
// 브루트포스로 모든 지점에서 M의 넓이 만큼 숫자 세기
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int T, N, M, result;
int arr[16][16];

int removeBug(int x, int y){
    int cnt;
    for(int i=x; i<x+M; i++){
        for(int j=y; j<y+M; j++){
            cnt += arr[i][j];
        }
    }
    return cnt;
}

int main(void){
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case){
        cin >> N >> M;
        result = 0;
        memset(arr, 0, sizeof(arr));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){ cin >> arr[i][j]; }
        }

        for(int i=0; i<N; i++){ 
            for(int j=0; j<N; j++){
                result = max(result, removeBug(i, j));
            }
        }

        cout << "#" << test_case << " " << result << "\n";
    }
}