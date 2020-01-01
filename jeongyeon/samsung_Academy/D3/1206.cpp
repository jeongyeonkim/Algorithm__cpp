#include <iostream>
#include <cmath>
using namespace std;
int t;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int Tcase, result;

    for(int t=1; t<=10; t++){
        Tcase = 0; result = 0;
        cin >> Tcase;

        int arr[Tcase+1];
        for(int i=0; i<Tcase; i++){
            cin >> arr[i];
        }

        for(int i=2; i<Tcase-2; i++){
            //왼쪽 오른쪽 2칸씩 arr[i]보다 작은지 확인
            if(arr[i] > arr[i-1] && arr[i] > arr[i-2] && arr[i] > arr[i+1] && arr[i] > arr[i+2]){
                int temp;
                temp = max(arr[i-2], max(arr[i-1], max(arr[i+1], arr[i+2])));
                result += arr[i] - temp;
            }
        }
        cout << "#" << t << " " << result << "\n";
    }
}