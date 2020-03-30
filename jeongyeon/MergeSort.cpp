// stl 없이 합병 정렬 구현
// 시간 복잡도 best - avg - worst >>> nlogn - nlogn - nlogn
#include <iostream>
using namespace std;
int N;
int temp[1000001], arr[1000001];

void Merge(int start, int mid, int end){
    int l = start, m = mid+1, nl = start;

    while (l <= mid && m <= end){ // 분할된거 병합
        if(arr[l] <= arr[m]){ temp[nl++] = arr[l++]; }
        else{ temp[nl++] = arr[m++]; }
    }
    if(l > mid){ // 남아있는 값들 복사
        for(int i=m; i<=end; i++){ temp[nl++] = arr[i]; }
    }
    else{
        for(int i=l; i<=mid; i++){ temp[nl++] = arr[i]; }
    }

    for(int i=start; i<=end; i++){ // 임시 배열 리스트 arr로 복사
        arr[i] = temp[i];
    }
}

void Divide(int start, int end){
    int mid = 0;

    if(start < end){
        mid = (start + end)/2;
        Divide(start, mid);
        Divide(mid+1, end);
        Merge(start, mid, end);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    
    for(int i=0; i<N; i++){ cin >> arr[i]; }

    Divide(0, N-1);

    for(int i=0; i<N; i++){ cout << arr[i] << "\n"; }
    return 0;
}