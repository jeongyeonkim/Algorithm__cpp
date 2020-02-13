// 베르트랑 공준
#include <iostream>
using namespace std;
#define MAX 246913
int N;
int arr[MAX];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    arr[1] = 1; 

    // 작은 수 부터 시작해서 배수에 미리 1을 입력해놓음
    for(int i=2; i<MAX; i++){
        if(arr[i] == 1){ continue; }
        for(int j = i*2; j<MAX; j+=i){
            arr[j] = 1;
        }
    }

    while (true){
        cin >> N;
        if(N == 0){ break; }
        int cnt = 0;

        for(int i=N+1; i<=2*N; i++){
            if(arr[i] == 0){ cnt++; }
        }
        cout << cnt << "\n";
    }

    return 0;
}