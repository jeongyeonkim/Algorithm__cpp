#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int K,N;
    cin >> N >> K;

    int left = 1, right = K, mid=0, result=0;
    while(left <= right){
        mid = (left + right) / 2;
        int cnt = 0;
        for(int i = 1;i<=N;i++){
            cnt += min(mid / i, N);
        }
        if(cnt < K){
            left = mid +1;
        }else{
            result = mid;
            right = mid -1;
        }
    }
    cout << result;
}