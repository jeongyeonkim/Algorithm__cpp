// 상근이의 여행
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int T, N, M;
int arr[1001][1001];
vector<int> result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i=0; i<M; i++){
            int a = 0, b = 0; cin >> a >> b;
        }
        result.push_back(N-1);
    }

    for(int i=0; i<result.size(); i++){ cout << result[i]<< "\n"; }
}