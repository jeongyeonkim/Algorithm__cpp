// 자두 나무
#include <iostream>
#include <algorithm>
using namespace std;
int T, W, result;
int arr[31][3];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T >> W;
    int temp = 0; cin >> temp;
    arr[0][temp]++;

    for(int i=1; i<T; i++){
        cin >> temp;

        for(int j=0; j<=W; j++){
            // 안 움직일 경우
            arr[j][temp]++;
            if(j != 0){
                // 움직이는 것이 안 움직이는 것보다 작을 경우
                if(arr[j-1][1] > arr[j][2]){
                    arr[j][2] = arr[j-1][1];
                }else if(arr[j-1][2] > arr[j][1]){
                    arr[j][1] = arr[j-1][2];
                }
            }
        }
    }

    // 최대 움직이는 수 내에서 가장 큰 값 result에 저장
    for(int i=0; i<=W; i++){
        result = max(result, arr[i][1]);
        result = max(result, arr[i][2]);
    }

    cout << result;
}