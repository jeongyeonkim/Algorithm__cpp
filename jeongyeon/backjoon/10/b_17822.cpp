// 원판돌리기
#include <iostream>
#include <deque>
using namespace std;
int N, M, T;
deque<int> arr[51];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> T;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int a = 0; cin >> a;
            arr[i].push_back(a);
        }
    }
    
    while (T--){
        
    }
    
}