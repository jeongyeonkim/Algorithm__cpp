// stl 없이 버블 정렬 구현
// 시간 복잡도 best - avg - worst >>>  n^2 - n^2 - n^2
#include <iostream>
using namespace std;
int N;
int arr[1001];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }

    for(int i=N-1; i>0; i--){
        int temp = -1;
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for(int i=0; i<N; i++){ cout << arr[i] << "\n"; }
    return 0;
}