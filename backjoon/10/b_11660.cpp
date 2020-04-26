// 구간 합치기
#include <iostream>
using namespace std;
int N, M, x1, y1, x2, y2;
long long result, sum;
int arr[1025][1025], arrSum[1025][1025];
int col[1025][1025], row[1025][1025];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
            col[i][j] += (col[i][j-1] + arr[i][j]);
            row[i][j] += (row[i-1][j] + arr[i][j]);
            
        }
    }

    while (M--){
        result = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1; i<=x2; i++){ result += col[i][y2]- col[i][y1-1];}
        
        cout << result << "\n";
    }

}