#include <iostream>
using namespace std;
long long fibonacci[15000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n=0;
    cin >> n;
    fibonacci[1]=1;
    
    for(int i=2; i<=15000000; i++){
        fibonacci[i] = (fibonacci[i-1]+fibonacci[i-2])%1000000;
    }
    
    cout << fibonacci[n%15000000];
    return 0;
}