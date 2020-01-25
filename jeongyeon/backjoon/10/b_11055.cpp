// 가장 큰 증가 부분 수열.
#include <iostream>
#include <vector>
using namespace std;
int N, result;
int arr[1001], seq[1001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }
    seq[0] = arr[0];

    for(int i=1; i<N; i++){
        int temp = 0;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                temp = max(temp, seq[j]);
            }
        }
        seq[i] += arr[i] + temp;
    }
    
    for(int i=0; i<N; i++){
        result = max(result, seq[i]);
    }
    
    cout << result;
}