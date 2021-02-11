// 외계인의 기타 연주
#include <iostream>
#include <stack>
using namespace std;
int N, P, result;
int input1, input2;
stack<int> arr[7];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> P;
    while (N--){
        cin >> input1 >> input2;

        if(arr[input1].empty()){
            arr[input1].push(input2);
            result++;
        }

        else{
            while (true){
                if(arr[input1].empty()){
                    arr[input1].push(input2);
                    result++;
                    break;
                }
                if(arr[input1].top() < input2){
                    arr[input1].push(input2);
                    result++;
                }
                else if(arr[input1].top() == input2){ break; }
                else{
                    arr[input1].pop();
                    result++;
                }
            }
        }
    }
    cout << result;
    return 0;
}