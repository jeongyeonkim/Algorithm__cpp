// 게임
#include <iostream>
#include <algorithm>
using namespace std;
long long X, Y, init;
long long result = 1e9;

void game(int low, int high){
    if(low > high){ return; }
    long long mid = (low + high) / 2;
    long long temp = (Y + mid) * 100 / (X + mid);
    
    if(temp > init){
        game(low, mid-1);
        result = min(result, mid);
    }else{ game(mid+1, high); }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> X >> Y;
    init = Y * 100 / X;
    if(init == 99 || init == 100){ cout << -1; return 0; }

    game(0,1e9);

    if(result == 21e9){ result = -1; }
    cout << result;
    return 0;
}