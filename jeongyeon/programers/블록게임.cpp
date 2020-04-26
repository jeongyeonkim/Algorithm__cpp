#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<vector<int>> arr;
int N;

bool bound(int x, int y){ // arr 범위 내 인지 체크
    if(x < 0 || y < 0 || x >= N || y >= N){ return false; }
    return true;
}

bool check(int x, int y, int row, int col){
    if(x + row > N || y + col > N){ return false; } // 영역 벗어날 경우

    int black = 0, num = -1;
    for(int i=x; i<x+row; i++){
        for(int j=y; j<y+col; j++){
            if(!bound(i, j)){ return false; }
            if(arr[i][j] == 0){
                int idx = i;
                while (idx > 0){ // 검은 블록 위에 다른 블록이 있을 경우 x
                    idx--;
                    if(arr[idx][j] != 0){ return false; }
                }
                black++;
                if(black > 2){ return false; } // 검은 블록이 2개 이상 필요할 경우 x
            }
            else if(num == -1){ num = arr[i][j]; }
            else if(num != arr[i][j]){ return false; }
        }
    }

    for(int i=x; i<x+row; i++){ // 없앨 수 있는 블록의 경우 자리 다 0으로 만들어서 블록 없애기
        for(int j=y; j<y+col; j++){ arr[i][j] = 0; }
    }

    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    arr = board;
    N = board.size();

    bool checkFind = false;
    while (true){
        checkFind = false;

        for(int i=0; i<N; i++){ // 전체 탐색면하서 3*2, 2*3 블록 형성 되는지 확인
            for(int j=0; j<N; j++){
                if(check(i, j, 2, 3) || check(i, j, 3, 2)){
                    answer++;
                    checkFind = true; // 블록 한개라도 없어지면 이전 블록도 다시 없앨수도 있기 때문에 다시 처음부터 탐색해야됨
                }
            }
        }

        if(!checkFind){ break; }
    }

    return answer;
}