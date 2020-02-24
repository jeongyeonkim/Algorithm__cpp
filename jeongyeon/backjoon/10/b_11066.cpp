// 파일 합치기
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int T, K;
int arr[501], sum[501];
int file[501][501];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> K;
        for(int i=1; i<=K; i++){
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }

        for(int i=2; i<=K; i++){
            for(int j=i-1; j>0; j--){
                file[j][i] = 999999999;
                for(int z=j; z<=i; z++){
                    file[j][i] = min(file[j][i], file[j][z] + file[z+1][i]);
                }
                file[j][i] += sum[i] - sum[j-1];
            }
        }
        
        cout << file[1][K] << "\n";
        memset(arr, 0, sizeof(arr));
        memset(file, 0, sizeof(file));
        memset(sum, 0, sizeof(sum));
    }
    
}