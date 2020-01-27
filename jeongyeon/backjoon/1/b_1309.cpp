// 동물원
#include <iostream>
#define K 9901
using namespace std;
int N, zoo[100001][3];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    zoo[1][0] = zoo[1][1] = zoo[1][2] = 1;
    
    for(int i=2; i<=N; i++){
        zoo[i][0] = (zoo[i-1][0] + zoo[i-1][1] + zoo[i-1][2])%K;
        zoo[i][1] = (zoo[i-1][0] + zoo[i-1][2])%K;
        zoo[i][2] = (zoo[i-1][0] + zoo[i-1][1])%K;
    }

    cout << (zoo[N][0]+zoo[N][1]+zoo[N][2])%K;
}