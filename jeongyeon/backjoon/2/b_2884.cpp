// 알람 시계
#include <iostream>
using namespace std;
int H, M;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> H >> M;

    if(M-45 > 0){
        M -= 45;
    }else{
        M += 15;
        if(H != 0){ H--; }
        else{ H = 23; }
    }

    cout << H << " " << M;
}