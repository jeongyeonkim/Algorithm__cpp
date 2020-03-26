// 행렬 제곱
// 시간 초과
#include <iostream>
#include <cmath>
#define K 1000;
using namespace std;
int N, B, even, cnt;
long long matrix[6][6], result[6][6], temp[6][6];

void setResult(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ temp[i][j] = result[i][j]; }
    }
}

long long Multiply(int a, int b){
    int r = 0;
    for(int i=0; i<N; i++){
        r += (temp[a][i]*temp[i][b])%K;
    }
    return r;
}

long long Multiply2(int a, int b){
    int r=0; 
    for(int i=0; i<N; i++){
        r += (temp[a][i]*matrix[i][b])%K;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> B;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
            result[i][j] = matrix[i][j];
        }
    }
    int m = 1;
    while (true){
        if(m == B){ break; }
        if(m*2 < B){
            setResult();
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    result[i][j] = Multiply(i, j)%K;
                }
            }
            m = m;
        }else{
            while(m < B){
                setResult();
                for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        result[i][j] = Multiply2(i, j)%K;
                    }
                }
                m++;
            }
            break;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}