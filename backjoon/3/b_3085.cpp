// 사탕 게임
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int N, result;
char arr[51][51], temp;
int dx[2] = {0, 1};
int dy[2] = {1, 0};

int checkCount(){
    int res = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<2; k++){
                int cnt = 1;
                int nx = i, ny = j;

                while (true){
                    if(nx + dx[k] < 0 || ny + dy[k] < 0 || nx + dx[k] >= N || ny + dy[k] >= N){ break; }
                    nx += dx[k]; ny += dy[k];
                    if(arr[nx][ny] != arr[i][j]){ break; }
                    cnt++;
                }
                
                res = max(res, cnt);
            }
        }
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    string str;
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<N; j++){ arr[i][j] = str[j]; }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<2; k++){
                if(i + dx[k] < 0 || j + dy[k] < 0 || i + dx[k] >= N || j + dy[k] >= N){ continue; }

                temp = arr[i][j];
                arr[i][j] = arr[i + dx[k]][j + dy[k]];
                arr[i + dx[k]][j + dy[k]] = temp;

                result = max(result, checkCount());

                temp = arr[i][j];
                arr[i][j] = arr[i + dx[k]][j + dy[k]];
                arr[i + dx[k]][j + dy[k]] = temp;
            }
        }
    }
 
    cout << result;
    return 0;
}