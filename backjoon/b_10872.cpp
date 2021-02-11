#include <iostream>
using namespace std;

int main(){
    int n=0, result=1;
    cin >> n;
    for(int i=n; i>=1; i--)
        result *= i;
    cout << result;
}