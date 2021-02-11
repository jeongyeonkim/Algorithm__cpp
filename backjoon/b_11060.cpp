#include <iostream>
#include <algorithm>
#define k 1001
using namespace std;
int N, result = k;
int arr[k], dp[k];

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i]; 
        dp[i] = 1001;
    }
    dp[0] = 0;

    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<=i+arr[i]; j++){
            dp[j] = min(dp[j], dp[i]+1);
        }
    }
    
    if(dp[N-1] == 1001){ cout << -1;}
    else{ cout << dp[N-1]; }
    
} 