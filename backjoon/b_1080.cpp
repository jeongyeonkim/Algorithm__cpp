#include <iostream>
using namespace std;

int N, M, cnt;
int matrixA[55][55], matrixB[55][55];
bool check = true;

void reverseA(int i, int j){
    for(int k=i; k<i+3; k++){
        for(int z=j; z<j+3; z++){
            matrixA[k][z] = 1-matrixA[k][z];
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ scanf("%1d", &matrixA[i][j]); }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ scanf("%1d", &matrixB[i][j]); }
    }

    for(int i=0; i<N-2; i++){
        for(int j=0; j<M-2; j++){
            if(matrixA[i][j] != matrixB[i][j]){
                reverseA(i, j);
                cnt++;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(matrixA[i][j] != matrixB[i][j]){ check = false; }
        }
    }
    if(check){ cout << cnt; }
    else{ cout << -1; }
}
