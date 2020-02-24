// 이차원 배열과 연산
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
int r, c, k, col = 3, row = 3;
int arr[101][101], arrCnt[101];
int result;

void Computation(){
    for(int m=0; m<=100; m++){
        if(arr[r][c] == k){ result = m; return; }

        // R연산
        if(row >= col){
            for (int i=1; i<=row; i++) {
                memset(arrCnt, 0, sizeof(arrCnt));
                for (int j=1; j<=col; j++) {
                    if (arr[i][j]) {
                        arrCnt[arr[i][j]]++;
                        // 갯수 세면 행렬 0으로 초기화
                        arr[i][j] = 0;
                    }
                }
                // 정렬을 위해서 우선순위 큐 사용
                priority_queue<pair<int, int> > que;
                for (int j=1; j<=100; j++) {
                    // 오름차순 정렬의 위해 입력에 -1 곱셈
                    if (arrCnt[j]) que.push(make_pair((-1)*arrCnt[j], (-1)*j));
                }
                int Size = que.size()*2;
                col = max(col, Size);
                for (int j=1; j<=Size; j+=2) {
                    arr[i][j] = (-1)*que.top().second;
                    arr[i][j+1] = (-1)*que.top().first;
                    que.pop();
                }
            }
        }
        
        // C연산
        else{
            for (int i=1; i<=col; i++) {
                priority_queue<pair<int, int> > que;
                memset(arrCnt, 0, sizeof(arrCnt));
                for (int j=1; j<=row; j++) {
                    if (arr[j][i]) {
                        arrCnt[arr[j][i]]++;
                        arr[j][i] = 0;
                    }
                }
                for (int j=1; j<=100; j++) {
                    if (arrCnt[j]) que.push(make_pair((-1)*arrCnt[j], (-1)*j));
                }
                int maxsize = que.size()*2;
                for (int j=1; j<=maxsize; j+=2) {
                    arr[j][i] = (-1)*que.top().second;
                    arr[j+1][i] = (-1)*que.top().first;
                    que.pop();
                }
                row = max(row, maxsize);
            }
        }
    }
    result = -1;
}
int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++){
        for(int j=1; j<=3; j++){ cin >> arr[i][j]; }
    }

    Computation();

    cout << result;
    return 0;
}