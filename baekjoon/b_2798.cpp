#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n=0, m=0, cardmax=0;
    cin >> n >> m;
    int arr[n];
    
    for(int i=0; i<n;i++)
        cin >> arr[i];
    
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k=j+1; k<n; k++){
                if(cardmax<(arr[i]+arr[j]+arr[k]) && (arr[i]+arr[j]+arr[k]) <= m)
                    cardmax = arr[i]+arr[j]+arr[k];
            }
        }
    }
    cout << cardmax;
    return 0;
}

