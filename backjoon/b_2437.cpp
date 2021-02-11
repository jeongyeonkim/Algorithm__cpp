// 저울
#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[1001], result;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) { cin >> arr[i]; }

    // 작은 숫자부터 시작하기 위하여 배열 오름차순으로 초기화.
    sort(arr, arr+N);
    for(int i=0; i<N; i++){
        // 지금까지 배열의 합에서 +1 한 값보다 다음 값이 크면 > 앞의 배열에서 뺄셈 및 덧셈으로 표현 불가.
        if(arr[i] > result+1) break;
        // 누적 합.
        result += arr[i];
    }

    cout << result+1;
}