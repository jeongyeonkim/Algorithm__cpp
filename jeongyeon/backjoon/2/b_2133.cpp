// 타일 채우기
#include <iostream>
using namespace std;
int N, result[31];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    if(N%2 != 0){
        cout << 0;
        return 0;
    }
    result[0] = 1;
    result[2] = 3;

    for(int i=4; i<=N; i++){
        for(int j=2; j<i; j+=2){
            if(j == 2){
                result[i] += result[i-j]*3;
            }else{
                result[i] += result[i-j]*2;
            }
        }
        result[i] += 2;
    }


    cout << result[N];
}