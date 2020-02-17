// [S/W 문제해결 기본] 4일차 - 길찾기
#include <iostream>
#include <string.h>
using namespace std;
int N, T, test_case;
int arr[101][2], visited[101];
bool result = false;

void road(int x){
    visited[x] = 1;
    if(x == 99){
        result = true;
        return;
    }
    
    for(int i=0; i<2; i++){
        if(visited[arr[x][i]] == 0 && !result){
            road(arr[x][i]);
        }
    }
}

int main(int argc, char** argv){
    for(test_case = 1; test_case <= 10; ++test_case){
        cin >> T >> N;
        for(int i=0; i<N; i++){
            int a = 0, b = 0;
            cin >> a >> b;
            if(arr[a][0] == 0){ arr[a][0] = b; }
            else{ arr[a][1] = b; }
        }

        road(0);
        if(result){ cout << "#" << test_case << " " << 1 << "\n";  }
        else{ cout << "#" << test_case << " " << 0 << "\n";  }
        
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        T = N = 0;
        result = false;
    }
    return 0;
}