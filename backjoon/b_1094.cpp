// 막대기
#include <iostream>
using namespace std;
int X, cnt;
int bar[7] = {64, 32, 16, 8, 4, 2, 1};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> X;
    for(int i=0; i<7; i++){
        if(X-bar[i] >= 0){
            cnt++;
            X -= bar[i];
            if(X <= 0){ break; }
        }
    }
    
    cout << cnt;
}