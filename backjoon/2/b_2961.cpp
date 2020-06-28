// 자와 각도기
#include <iostream>
using namespace std;
int N, K;
int arrN[11], resultK[11], num[361];

void sol(){

}

int main(void){
    ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i=0; i<N; i++){ cin >> arrN[i]; }
    for(int i=0; i<K; i++){ cin >> resultK[i]; }



    for(int i=0; i<K; i++){
        if(num[resultK[i]] == 1){ cout << "YES\n"; }
        else{ cout << "NO\n"; }
    }
    return 0;
}