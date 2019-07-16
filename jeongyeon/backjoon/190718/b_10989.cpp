#include <iostream>
using namespace std;
int count[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0, arr=0;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr;
        count[arr]++;
    }
    for(int i=1; i<10001;i++){
        for(int j=0; j<count[i]; j++)
            cout << i << "\n";
    }
    return 0;    
}