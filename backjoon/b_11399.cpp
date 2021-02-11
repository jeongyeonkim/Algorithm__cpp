#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n=0, output=0;
    cin >> n;
    int arr[n]; int greedy[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    greedy[0] = arr[0];
    for(int i=1; i<n; i++)
        greedy[i] = greedy[i-1] + arr[i];
    
    for(int i=0; i<n; i++)
        output += greedy[i];

    cout << output;
    return 0;
}