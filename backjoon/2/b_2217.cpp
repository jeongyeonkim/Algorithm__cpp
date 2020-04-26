#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b){
    return a>b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0, MAX=0;
    cin >> n;
    int arr[n+1];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n, desc);
    MAX = arr[0];
    for(int i=1; i<n; i++){
        if(MAX < arr[i]*(i+1))
            MAX = arr[i]*(i+1);
    }
    
    cout << MAX;
    return 0;
}