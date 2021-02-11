#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int num=0, count=1, value=1;
    cin >> num;
    
    while(num > value){
        value += (6*count);
        count++;
    }
    cout << count;
    return 0;
}