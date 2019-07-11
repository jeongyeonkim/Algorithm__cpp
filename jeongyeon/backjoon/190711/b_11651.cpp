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
    
    pair <int, int> p[n];
    
    for(int i=0; i<n; i++){
        cin >> p[i].second >> p[i].first; 
    }
    sort(p, p+n);
    for(int i=0; i<n-1; i++){
        if(p[i].first == p[i+1].first && p[i].second > p[i+1].second){
            swap(p[i], p[i+1]);
        }
    }
    
    for(int i=0; i<n; i++)
        cout << p[i].second << " " << p[i].first << "\n";
    return 0;
}

