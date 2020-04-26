#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;


bool desc(int a, int b){
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string num;
    cin >> num;
    int arr[num.length()];
    string arrchar[num.length()];
    
    for(int i=0; i<num.length(); i++){
        arrchar[i] = num.substr(i,1);
        arr[i] = atoi(arrchar[i].c_str());
    }
    sort(arr, arr+num.length(), desc);
    
    for(int i=0; i<num.length(); i++)
        cout << arr[i];    
    return 0;
}
