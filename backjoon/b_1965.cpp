// 상자 넣기
#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[1001], box[1001], boxMax;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        box[i] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            if(arr[i] > arr[j]){ box[i] = max(box[j]+1, box[i]); }
            boxMax = max(boxMax, box[i]);
        }
    }
    cout << boxMax;
}