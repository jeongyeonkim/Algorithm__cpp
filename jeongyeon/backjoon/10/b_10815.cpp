#include <iostream>
#include <algorithm>
using namespace std;
int arr[500001], result[500001];

int num(int n, int start, int end){
    int mid = (start + end)/2;
    if(start > end){
        return 0;
    }
    if(n == arr[mid]){
        return 1;
    }
    if(n > arr[mid]){
        return num(n, mid+1, end);
    }else{
        return num(n, start, mid-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M; cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);
    cin >> M;

    for(int i=0; i<M; i++){
        int n;
        cin >> n;
        result[i] = num(n, 0, N-1);
    }

    for(int i=0; i<M; i++){
        cout << result[i] << " ";
    }
}