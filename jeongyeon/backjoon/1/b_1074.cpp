#include <iostream>
#include <cmath>
using namespace std;
int N, r, c, cnt;

void Z(int row, int col, int z){
    if(row == r && col == c){
        cout << cnt;
        return;
    }
    if(r < row + z && r >= row && c < col + z && c >= col){
        Z(row, col, z/2);
        Z(row, col + z/2, z/2);
        Z(row + z/2, col, z/2);
        Z(row + z/2, col + z/2, z/2);
    }else{
        cnt += z*z;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> r >> c;
    Z(0,0, pow(2,N));
}