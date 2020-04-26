#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N=0; cin >> N;
    int n=N, k=0, sum=0;
    while(N>0){
        N /= 10;
        k++;
    }
    for(int i=k-1; i>=0; i--){
        sum += (int)(n/pow(10,i));
        n %= (int)pow(10,i);
    }
    cout << sum;
}