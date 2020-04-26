// 시험 감독
#include <iostream>
using namespace std;
const int MAX = 1000001;
int N, B, C;
int arr[MAX];
long long result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){ cin >> arr[i]; }
    cin >> B >> C;
    for(int i=0; i<N; i++){
        result++;
        arr[i] -= B;
        if(arr[i] < 0){ continue; }

        if(arr[i]/(double)C > arr[i]/C){ result++; }
        result += arr[i]/C;
    }

    cout << result;
}