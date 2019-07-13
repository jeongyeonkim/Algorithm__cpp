#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0, count=0;
    cin >> n;
    tuple <int, int, string> arr[n];
    
    for(int i=0; i<n; i++){
        int first;
        string second;
        cin >> first >> second;
        arr[i] = make_tuple(first, count, second);
        count++;
    }
    sort(arr, arr+n);
   
    for(int i=0; i<n; i++)
        cout << get<0>(arr[i]) << " " << get<2>(arr[i]) << "\n";
}
