// 알람 시계
#include <iostream>
using namespace std;
int H, M;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> H >> M;

    M -= 45;
    if(M < 0){
        M += 60;
        H--;
    }

    if(H < 0){
        H = 23;
    }

    cout << H << " " << M;
}