// Z
#include <iostream>
#include <cmath>
using namespace std;
int N, r, c, cnt;

void Z(int a, int b, int size){
    if(a == r && b == c){
        cout << cnt;
        return;
    }

    int half = size/2;

    if(r < a+size && r >= a && c < b+size && c >= b){
        Z(a, b, half);
        Z(a, b+half, half);
        Z(a+half, b, half);
        Z(a+half, b+half, half);
    }else{
        cnt += size*size;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> r >> c;

    Z(0, 0, pow(2,N));
}