#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a=0,b=0;
    while(true){
        cin >> a >> b;
        if(a==0 && b==0)
            return 0;
        if(b%a == 0)
            cout << "factor" <<"\n";
        else if(a%b == 0)
            cout << "multiple" << "\n";
        else
            cout << "neither" << "\n";
    }
    return 0;
}
