#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0;
    cin >> n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        cout << arr[i] << "\n";
    }
    
}
