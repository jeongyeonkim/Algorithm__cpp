#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0, MAX=1, end=0;
    cin >> n;
    pair <int, int> arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i].second >> arr[i].first;
        
    sort(arr, arr+n);
    end = arr[0].first;
    for(int i=1; i<n; i++){
       if(end <= arr[i].second){
           MAX++;
           end = arr[i].first;
        }
    }
    cout << MAX;
    return 0;
}