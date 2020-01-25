// #include <iostream>
// using namespace std;
// long long fibonacci[15000001];

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     long long n=0;
//     cin >> n;
//     fibonacci[1]=1;
    
//     for(int i=2; i<=15000000; i++){
//         fibonacci[i] = (fibonacci[i-1]+fibonacci[i-2])%1000000;
//     }

//     cout << fibonacci[n%15000000];
//     return 0;
// }

// 시간 초과
#include <iostream>
#define K 1000000
using namespace std;
long long n;
long long fibo[3];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    fibo[1] = 1;

    for(int i=0; i<n-1; i++){
        fibo[2] = (fibo[0] + fibo[1])%K;
        fibo[0] = fibo[1];
        fibo[1] = fibo[2];
    }
    cout << fibo[2];
}