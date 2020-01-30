// 체스판 다 칠하기.
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, result = 64;
char chessBoard[51][51];
char temp[2][8] = {{'B','W','B','W','B','W','B','W' },{'W','B','W','B','W','B','W','B'}};

int paint(int x, int y){
    int cnt = 0;
    int k = 0;
    if(chessBoard[x][y] != 'B'){ k = 1; }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(chessBoard[x+i][y+j] != temp[k][j]){
                cnt++;
            }
        }
        if(k == 0){ k = 1;}
        else{ k = 0; }
    }
    return cnt;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ cin >> chessBoard[i][j]; }
    }

    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            result = min(result, paint(i,j));
            if(chessBoard[i][j] == 'B'){ chessBoard[i][j] = 'W'; }
            else{ chessBoard[i][j] = 'B'; }
            result = min(result, paint(i,j)+1);
        }
    }

    cout << result;
}