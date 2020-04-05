// [모의 SW 역량테스트] 벽돌 깨기
#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int T, N, X, Y, result = 1e9;
int arr[16][13], temp[16][13], seleted[5];

struct info{
    int x, y, depth;
};

void copyArr(){ // 배열 복사
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){ temp[i][j] = arr[i][j]; }
    }
}

int cntBrick(){ // 벽돌 이동 및 갯수 세기
    int cnt = 0;
    for(int i=0; i<Y; i++){
        queue<int> que;
        for(int j=X-1; j>=0; j--){
            if(temp[j][i] != 0){ que.push(temp[j][i]); } // 벽돌 값 밑에서부터 담기
            temp[j][i] = 0;
        }

        cnt += que.size();

        int idx = X-1;
        while(!que.empty()){
            temp[idx][i] = que.front(); // 벽돌 값 밑에서부터 넣기
            que.pop();
            idx--;
        }
    }

    return cnt;
}

void breakBrick(int cnt){ // 벽돌 부수기
    if(result == 0){ return; } // 이미 벽돌이 다 부셔져있을 경우 탐색할 필요 없음
    if(cnt < 0){ return; }

    queue<info> que;
    for(int i=0; i<X; i++){ // 최상단 벽돌 찾아서 queue에 넣기
        if(temp[i][seleted[cnt]] != 0){
            que.push({i, seleted[cnt], temp[i][seleted[cnt]]});
            break;
        }
    }

    while (!que.empty()){
        int len = que.size();

        for(int i=0; i<len; i++){
            int x = que.front().x;
            int y = que.front().y;
            int depth = que.front().depth;
            que.pop();
            temp[x][y] = 0;

            for(int j=x-1; j>x-depth; j--){ // 상
                if(j < 0){ break;}
                if(temp[j][y] > 1){ que.push({j, y, temp[j][y]}); }
                temp[j][y] = 0;
            }
            for(int j=y+1; j<y+depth; j++){ // 우
                if(j >= Y){ break; }
                if(temp[x][j] > 1){ que.push({x, j, temp[x][j]}); }
                temp[x][j] = 0;
            }
            for(int j=x+1; j<x+depth; j++){ // 하
                if(j >= X){ break; }
                if(temp[j][y] > 1){ que.push({j, y, temp[j][y]}); }
                temp[j][y] = 0;
            }
            for(int j=y-1; j>y-depth; j--){ // 좌
                if(j < 0){ break; }
                if(temp[x][j] > 1){ que.push({x, j, temp[x][j]}); }
                temp[x][j] = 0;
            }
        }
    }
    
    result = min(result, cntBrick()); // 남은 벽돌 최소 값 갱신
    breakBrick(cnt - 1);
}

void selectBrick(int cnt, int idx){ 
    if(result == 0){ return; } // 이미 벽돌이 다 부셔져있을 경우 탐색할 필요 없음
    if(cnt == N){
        copyArr();
        breakBrick(cnt-1);
        return;
    }

    for(int i=0; i<Y; i++){
        seleted[idx] = i;
        selectBrick(cnt + 1, idx + 1);
    }
}

int main(int argc, char** argv){
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case){
        cin >> N >> Y >> X;
        for(int i=0; i<X; i++){
            for(int j=0; j<Y; j++){ cin >> arr[i][j]; }
        }
        
        selectBrick(0, 0);

        cout << "#" << test_case << " " << result << "\n"; 
        memset(arr, 0, sizeof(arr));
        result = 1e9;
        memset(seleted, 0, sizeof(seleted));
        memset(temp, 0, sizeof(temp));
    }
    return 0;
}