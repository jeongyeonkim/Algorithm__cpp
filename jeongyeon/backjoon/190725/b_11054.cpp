#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int n=0, MAX=0; cin >> n;
    int input[n], dp_1[n], dp_2[n];
    for(int i=0; i<n; i++){
        cin >> input[i];
        dp_1[i] = 1;
        dp_2[i] = 0;
    }
    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            if(input[i] > input[j]){
                dp_1[i] = max(dp_1[j]+1, dp_1[i]);
            }
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(input[i] > input[j]){
                dp_2[i] = max(dp_2[j]+1, dp_2[i]);
            }
        }
    }
    for(int i=0; i<n; i++)
        MAX = max(MAX, dp_1[i]+dp_2[i]);
    cout << MAX;
    return 0;
}