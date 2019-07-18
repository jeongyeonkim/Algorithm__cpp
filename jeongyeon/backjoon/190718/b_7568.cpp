#include <iostream>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0;
    cin >> n;
    int rank[n];
    pair <int, int> arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
        rank[i] = 1;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i].first < arr[j].first && arr[i].second < arr[j].second)
                rank[i]++;
        }
    }
    
    for(int i=0; i<n; i++)
        cout << rank[i] << "\n";
}