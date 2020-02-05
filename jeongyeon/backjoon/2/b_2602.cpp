// 돌다리 건너기
#include <iostream>
#include <string.h>
using namespace std;
string arr1, arr2, step;
string arr[2];
int result, stone[101][21];

int bridge(int x, int y, int i){
    if(stone[y][i] != 0){ return stone[y][i]; }
    if(i == step.length()){ return 1; }
    if(y >= arr[1].length()){ return 0; }

    for(int j=y; j<arr[0].length(); j++){
        if(step[i] == arr[x].at(j)){
            stone[y][i] += bridge(1-x, j+1, i+1);
        }
    }
    return stone[y][i];
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> step;
    cin >> arr[0] >> arr[1];

    result += bridge(0, 0, 0);
    memset(stone, 0 ,sizeof(stone));
    result += bridge(1, 0, 0);

    cout << result;
}