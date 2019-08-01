#include <iostream>
using namespace std;
long long a, b, c;

long long cal(long long A, long long B){
    if(B == 0)
        return 1;
    else if (B == 1)
        return A%c;
    else if(B%2 == 1)
        return (A*(cal(A, B-1)%c)%c);
    else 
        return ((cal(A,B/2)%c)*(cal(A,B/2)%c)%c);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    cout << cal(a,b) << "\n";
    return 0;
}