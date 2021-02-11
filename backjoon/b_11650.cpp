#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0;
    cin >> n;
    pair <int,int> arr[n];
    
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+n);
    for(int i=0; i<n-1; i++){
        if(arr[i].first == arr[i+1].first && arr[i].second > arr[i+1].second){
            swap(arr[i], arr[i+1]);
        }
    }
    for(int i=0; i<n ; i++)
        cout << arr[i].first << " " << arr[i].second << "\n";
}
