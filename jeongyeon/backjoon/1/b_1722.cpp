// 순열의 순서
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, num;
long long k;
long long cnt[21];
bool check[21];
int result[21], temp[21];
vector<int> arr;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    // 배열에 1~N 숫자 넣기
    for(int i=1; i<=N; i++){ arr.push_back(i); }
    // N!, (N-1)! ..... 값 배열에 넣기
    cnt[0] = 1;
    for(int i=1; i<=N; i++){ cnt[i] = cnt[i-1] * i; }

    cin >> num ;
    // k번째 순열 구하기
    if(num == 1){
        cin >> k;

        for(int i=0; i<N; i++){
            for(int j=1; j<=N; j++){
                // 이미 들어간 숫자인지 체크
                if(!check[j]){
                    if(cnt[N-i-1] < k){ k -= cnt[N-i-1]; }
                    else{
                        result[i] = j;
                        check[j] = true;
                        break;
                    }
                }
            }
        }

        for(int i=0; i<N; i++){ cout << result[i] << " "; }
    }

    // 몇번째 수열인지 구하기
    else{
        for(int i=0; i<N; i++){ cin >> temp[i]; }
        long long result2 = 0;

        for(int i=0; i<N; i++){
            for(int j=1; j<temp[i]; j++){
                if(!check[j]){ result2 += cnt[N-i-1]; }
            }
            check[temp[i]] = true;
        }

        cout << result2 + 1;
    }

    return 0;
}