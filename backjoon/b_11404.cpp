// 플로이드
#include <iostream>
using namespace std;
int n, m;
int arr[101][101];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        if(arr[a][b] == 0){ arr[a][b] = c; }
        else{ arr[a][b] = min(arr[a][b], c); }
    }

    // 중간 경로 거쳐서 가는 비용이 더 적은지 인지 확인
    for(int i=1; i<=n; i++){
        for(int start=1; start<=n; start++){
            if(arr[start][i] == 0){ continue; }
            
            for(int end=1; end<=n; end++){
                if(arr[i][end] == 0 || start == end){ continue; }

                if(arr[start][end] == 0 || arr[start][end] > arr[start][i] + arr[i][end]){
                    arr[start][end] = arr[start][i] + arr[i][end];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){ cout << arr[i][j] << " "; }
        cout << "\n";
    }
    return 0;
}