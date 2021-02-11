// 배열 돌리기4
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, A, B, C, result = 1e9;
int arr[51][51], temp[51][51];
int computation[51][3], selected[7], R[7];

void sumRow(){ // 행의 합
    int res = 1e9;
    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=0; j<M; j++){ sum += temp[i][j]; }
        res = min(res, sum); // 행의 합이 최소인거 res에 저장
    }
    result = min(result, res); // 가장 작은 A 행렬 값 넣음
}

void copyArr(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){ temp[i][j] = arr[i][j]; }
    }
}

void Rotation(){
    copyArr();
    for(int i=0; i<K; i++){
        int r = computation[R[i]][0], c = computation[R[i]][1], s = computation[R[i]][2]; // (r, c) = 중심 좌표
        int sizeArr = s*2 + 1;
        int startX = r-s, startY = c-s;
        while (true){
            if(startX == r && startY == c){ break; }
            int num = temp[startX][startY]; // 맨 처음 시작 점 값 저장
            int endX = startX + sizeArr - 1;
            int endY = startY + sizeArr - 1;

            for(int j=startX; j<endX; j++){ // 남
                temp[j][startY] = temp[j+1][startY];
            }
            for(int j=startY; j<startY + sizeArr -1; j++){ // 동
                temp[endX][j] = temp[endX][j+1];
            }
            for(int j=endX; j>startX; j--){ // 북
                temp[j][endY] = temp[j-1][endY];
            }
            for(int j=endY; j>startY; j--){ // 서
                temp[startX][j] = temp[startX][j-1];
            }
            temp[startX][startY+1] = num;
            startX++; startY++; sizeArr -= 2;
        }
    }
    sumRow();
}

void selectIdx(int cnt){ // 회전 연산 조합
    if(cnt == K){
        Rotation();
        return;
    }

    for(int i=0; i<K; i++){
        if(selected[i]){ continue; }
        R[cnt] = i;
        selected[i] = 1;
        selectIdx(cnt + 1);
        selected[i] = 0;
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            temp[i][j] = arr[i][j];
        }
    }
    for(int i=0; i<K; i++){
        cin >> A >> B >> C;
        computation[i][0] = A-1;
        computation[i][1] = B-1;
        computation[i][2] = C;
    }

    selectIdx(0);

    cout << result;
    return 0;
}