// stl 없이 퀵정렬 구현
// 시간 복잡도 best - avg - worst >>> nlogn - nlogn - n^2
#include <iostream>
using namespace std;
int N;
int arr[1000001];

void Quicksort(int start, int end){
    if(start >= end){ return; }
    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;

    while (i <= j){
        while (i <= end && arr[i] <= arr[pivot]){ i++; }
        while (j > start && arr[j] >= arr[pivot]){ j--; }

        if(i > j){
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }else{
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    Quicksort(start, j-1);
    Quicksort(j+1, end);
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }

    Quicksort(0, N-1);

    for(int i=0; i<N; i++){ cout << arr[i] << "\n"; }
    return 0;
}