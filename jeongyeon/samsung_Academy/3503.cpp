// 초보자를 위한 점프대 배치하기
#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
int test_case, T, N;
int arr[10001], temp[10001];
int result;

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        for(int i=0; i<N; i++){ cin >> arr[i]; }

        sort(arr, arr+N);

        bool check = true;
        int ri = N-1, le = 0;
        // 정렬된 배열에서 작은 수 부터 왼쪽 오른쪽에 하나씩 넣음
        for(int i=0; i<N; i++){
            if(check){
                temp[le] = arr[i];
                le++;
                check = false;
            }else{
                temp[ri] = arr[i];
                ri--;
                check = true;
            }
        }

        for(int i=1; i<N; i++){
            result = max(result, abs(temp[i] - temp[i-1]));
        }

        result = max(result, abs(temp[0] - temp[N-1]));
        
        cout << "#" << test_case << " " << result << "\n"; 
        memset(arr, 0, sizeof(arr));
        memset(temp, 0, sizeof(0));
        result = 0;
    }
    return 0;
}