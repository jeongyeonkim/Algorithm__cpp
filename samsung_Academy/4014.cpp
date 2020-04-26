// [모의 SW 역량테스트] 활주로 건설
#include <iostream>
#include <string.h>
using namespace std;
int test_case, T, result, N, X;
int arr[21][21], check[21][21];

bool checkRow(int x){
    for(int i=0; i<N-1; i++){
        int k = arr[x][i] - arr[x][i+1];

        if(k > 1 || k <-1){ return false; }
        if(k == 1){
            for(int s=i+1; s<=i+X; s++){
                if(s >= N){ return false; }
                if(arr[x][i+1] != arr[x][s]){ return false; }
                check[x][s] = 1;
            }
        }else if(k == -1){
            for(int s=i; s>i-X; s--){
                if(s<0){ return false; }
                if(arr[x][s] != arr[x][i]){ return false; }
                if(check[x][s]){ return false; }
                check[x][s] = 1;
            }
        }
    }
    return true;
}

bool checkCol(int x){
    for(int i=0; i<N-1; i++){
        int k = arr[i][x] - arr[i+1][x];

        if(k > 1 || k < -1){ return false; }
        else if(k == 1){
            for(int s=i+1; s<=i+X; s++){
                if(s >= N){ return false; }
                if(arr[i+1][x] != arr[s][x]){ return false; }
                check[s][x] = 1;
            }
        }
        else if(k == -1){
            for(int s=i; s>i-X; s--){
                if(s<0){ return false; }
                if(arr[i][x] != arr[s][x]){ return false; }
                if(check[s][x]){ return false; }
                check[s][x] = 1;
            }
        }
    }
    return true;
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N>> X;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){ cin >> arr[i][j]; }
        }

        for(int i=0; i<N; i++){ // 세로 활주로
            if(checkCol(i)){ result++; }
        }

        memset(check, 0, sizeof(check));
        for(int i=0; i<N; i++){
            if(checkRow(i)){ result++; }
        }

        cout << "#" << test_case << " " << result << "\n"; 
        result = 0;
        memset(arr, 0, sizeof(arr));
        memset(check, 0 ,sizeof(check));
    }
    return 0;
}
