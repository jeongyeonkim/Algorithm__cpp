#include <iostream>
#include <cmath>
#define K 1000;
using namespace std;
int N, B, even, cnt;
int matrix[6][6], result[6][6], temp[6][6];

void setResult(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ temp[i][j] = result[i][j]; }
    }
}
int Multiply(int a, int b){
    int r = 0;
    for(int i=0; i<N; i++){
        r += (temp[a][i]*temp[i][b])%K;
    }
    return r;
}

int Multiply2(int a, int b){
    int r=0; 
    for(int i=0; i<N; i++){
        r += (temp[a][i]*matrix[i][b])%K;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> B;
    for(int i=0; i<50; i++){
        if(pow(2,cnt) < B){
            cnt++;
        }else{
            cnt--;
            break;
        }
    }
    

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> matrix[i][j];
            temp[i][j] = matrix[i][j];
        }
    }

    for(int k=0; k<cnt; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                result[i][j] = Multiply(i,j)%K;
            }
        }
        setResult();
    }

    for(int k=0; k<B-pow(2,cnt); k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                result[i][j] = Multiply2(i,j)%K;
            }
        }
        setResult();
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}