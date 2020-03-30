// stl 없이 힙 정렬 구현
// 시간 복잡도 best - avg - worst >>>  nlogn - nlogn - nlogn
#include <iostream>
using namespace std;
int N;
int arr[1000001];

void heap(int num){
    for(int i=1; i<num; i++){
        int child = i;
        while (child > 0){
            int root = (child-1)/2;
            if(arr[root] < arr[child]){
                int temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
            }
            child = root;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }
    heap(N);
    
    for(int i=N-1; i>=0; i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heap(i);
    }

    for(int i=0; i<N; i++){ cout << arr[i] <<"\n"; }
    return 0;
}