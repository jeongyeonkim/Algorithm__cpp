// stl 없이 삽입 정렬 구현
// 시간 복잡도 best - avg - worst >>> n - n^2 - n^2
#include <iostream>
using namespace std;
int N;
int arr[1001];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }

    for(int i=1; i<N; i++){
        int temp = arr[i], j = 0;
        for(j=i-1; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;
    }

    for(int i=0; i<N; i++){ cout << arr[i] << "\n"; }
    return 0;
}