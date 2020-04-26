// 경사로
#include <iostream>
#include <string.h>
using namespace std;
int n, len, result;
int arr[101][101];
bool check[101][101];

bool checkRow(int x){
    for(int i=0;  i<n-1; i++){
        if(arr[x][i] - arr[x][i+1] == 1){
            for(int start=i+1; start<=i+len; start++){
                // 범위 벗어나는 경우
                if(start >= n){ return false; }
                // 칸의 높이가 같지 않을 때
                if(arr[x][i+1] != arr[x][start]){ return false; }
                // 경사로 놓기
                check[x][start] = true;
            }
        }
        else if(arr[x][i] - arr[x][i+1] == -1){
            for(int start=i; start>i-len; start--){
                if(start < 0){ return false; }
                if(arr[x][i] != arr[x][start]){ return false; }
                if(check[x][start]){ return false; }
                check[x][start] = true;
            }
        }
        else if(arr[x][i] - arr[x][i+1] > 1 || arr[x][i] - arr[x][i+1] < -1){ return false; }
    }
    return true;
}

bool checkCol(int x){
    for(int i=0;  i<n-1; i++){
        if(arr[i][x] - arr[i+1][x] == 1){
            for(int start=i+1; start<=i+len; start++){
                // 범위 벗어나는 경우
                if(start >= n){ return false; }
                // 칸의 높이가 같지 않을 때
                if(arr[i+1][x] != arr[start][x]){ return false; }
                // 경사로 놓기
                check[start][x] = true;
            }
        }
        else if(arr[i][x] - arr[i+1][x] == -1){
            for(int start=i; start>i-len; start--){
                if(start < 0){ return false; }
                if(arr[i][x] != arr[start][x]){ return false; }
                if(check[start][x]){ return false; }
                check[start][x] = true;
            }
        }
        else if(arr[i][x] - arr[i+1][x] > 1 || arr[i][x] - arr[i+1][x] < -1){ return false; }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> len;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){ cin >> arr[i][j] ;}
    }

    for(int i=0; i<n; i++){ if(checkRow(i)){ result++; } }
	
    memset(check, 0, sizeof(check));
    for(int i=0; i<n; i++){ if(checkCol(i)){ result++; } }

    cout << result;
	return 0;
}