// stl 없이 선택 정렬 구현
// 시간 복잡도 best - avg - worst >>> n^2 - n^2 - n^2
#include <iostream>
using namespace std;
int N;
int arr[10001];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }

    for(int i=0; i<N-1; i++){
        int temp = arr[i], tempPos = -1;
        for(int j=i+1; j<N; j++){
            if(temp > arr[j]){
                temp = arr[j];
                tempPos = j;
            }
        }
        if(tempPos != -1){ arr[tempPos] = arr[i]; }
        arr[i] = temp;
    }

    for(int i=0; i<N; i++){ cout << arr[i] << "\n"; }
}