// 공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, C;
vector<int> arr;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> C;
    for(int i=0; i<N; i++){
        int a = 0; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int low = 1, high = arr[N-1] - arr[0];
    int mid = 0;

    while (low <= high){
        mid = (low + high) / 2;
        int cnt = 1;
        // here = 마지막으로 저장한 공유기의 위치
        int here = arr[0];

        for(int i=1; i<N; i++){
            if(arr[i] - here > mid){
                here = arr[i];
                cnt++;
            }
        }

        if(C > cnt){ high = mid - 1; }
        else{ low = mid + 1; }
    }

    cout << low;
    return 0;
}