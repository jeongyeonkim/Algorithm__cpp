//예산
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int N, M, result;

void Budget(int start, int end){
    int mid = (start + end) / 2 ; 
    long long sum = 0;
    if(start > end){ return; }
    for(int i=0; i<N; i++){
        sum += min(arr[i], mid);
    }

    if(sum > M){
        Budget(start, mid-1);   
    }else{
        result = mid;
        Budget(mid+1, end);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N; int maxBuget = 0;
    for(int i=0; i<N; i++){ 
        cin >> arr[i];
        maxBuget = max(arr[i], maxBuget);
    }
    cin >> M;

    Budget(0, maxBuget);
    cout << result;
}