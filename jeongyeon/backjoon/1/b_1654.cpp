#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
int N, K;
long long arrLen[MAX];

bool check(int mid){
    int centimeter=0;
    for(int i=0; i<N; i++){
        centimeter += arrLen[i]/mid;
    }
    if(centimeter >= K)
        return true;
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    long long right=0, resultMAX=0;
    for(int i=0; i<N; i++){
        cin >> arrLen[i];
        right = max(right, arrLen[i]);
    }
    long long left=1;
    while(left <= right){
        long long mid = (left+right)/2;
        if(check(mid)){
            resultMAX = max(resultMAX, mid);
            left = mid+1;
        }
        else
            right = mid-1;
    }
    cout << resultMAX;
    return 0;
}