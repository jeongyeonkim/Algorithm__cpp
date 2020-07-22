// 링크와 스타드
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int N, result = 1e9, l, s;
int arr[21][21];
int link[21], start[21];

void colculation(){
    int resLink = 0, resStart = 0;
    for(int i=0; i<l; i++){
        for(int j=0; j<l; j++){
            resLink += arr[link[i]][link[j]];
        }
    }
    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
            resStart += arr[start[i]][start[j]];
        }
    }
    
    result = min(result, abs(resStart - resLink));
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ cin >> arr[i][j]; }
    }
    
    for(int i=0; i<(1<<N); i++){
        memset(link, 0, sizeof(link));
        memset(start, 0, sizeof(start));
        s = 0, l = 0;
        for(int j=0; j<N; j++){
            if(i & (1 << j)){ link[l++] = j; }
            else{ start[s++] = j; }
        }
        colculation();
    }
    
    
    cout << result;
    return 0;
}
