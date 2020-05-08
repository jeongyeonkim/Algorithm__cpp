#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
char arr[31][31];
int temp[31][31];
int M, N, answer;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

void moveArr(){ // 없어진 블록 제외하고 이동
    int cnt = 0;
    for(int i=0; i<M; i++){
        queue<int> que;
        for(int j=N-1; j>=0; j--){
            if(temp[j][i] != 1 && arr[j][i] != '0'){
                que.push(arr[j][i]);
            }
            else{ cnt++; }
            arr[j][i] = '0';
        }
        int idx = N-1;
        while (!que.empty()){
            arr[idx][i] = que.front();
            que.pop();
            idx--;
        }
    }
    answer = cnt;
}

bool check(int x, int y){ // 사각형 형성이 가능한지 체크
    char t = arr[x][y];
    for(int i=0; i<3; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(arr[nx][ny] != t){ return false; }
    }
    return true;
}

bool game(){
    memset(temp, 0, sizeof(temp));
    bool flag = false;

    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            if(arr[i][j] != '0' && check(i, j)){ // 사각형이 같으면
                flag = true; // 블록 삭제 할 수 있으면 블록 이동할 수 있게
                temp[i][j] = 1; 
                for(int k=0; k<3; k++){ temp[i + dx[k]][j + dy[k]] = 1; }
            }
        }
    }

    return flag;
}

int solution(int m, int n, vector<string> board) {
    N = m; M = n;
    for(int i=0; i<m; i++){ // 블록 이동을 위해서 array로 저장
        for(int j=0; j<n; j++){
            arr[i][j] = board[i][j];
        }
    }

    while(game()){ moveArr(); } // 사각형 형성되는게 하나라도 있으면 블록 이동

    return answer;
}