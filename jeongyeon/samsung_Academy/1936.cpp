#include <iostream>
using namespace std;

int main(){
    int a=0, b=0; cin >> a >> b;
    if(a == 1){
        if(b == 2)
            cout << "B";
        else
            cout << "A";
    }else if(a == 2){
        if(b == 1)
            cout << "A";
        else
            cout << "B";
    }else{
        if(b == 1)
            cout << "B";
        else
            cout << "A";
    }
}