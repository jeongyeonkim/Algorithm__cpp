// 기타리스트
#include <iostream>
using namespace std;
int N, S, M, result = -1;
int song[101], volume[101][1001];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> S >> M;
    for(int i=1; i<=N; i++){ cin >> song[i]; }

    volume[0][S] = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<=M; j++){
            if(volume[i][j] == 1){
                if(j + song[i+1] <= M){ volume[i+1][j+song[i+1]] = 1; }
                if(j - song[i+1] >= 0){ volume[i+1][j-song[i+1]] = 1; }
            }
        }
    }

    for(int i=0; i<=M; i++){
        if(volume[N][i] == 1){ result = i; }
    }

    cout << result;
}