// 1, 2, 3 더하기 2
#include <iostream>
using namespace std;
int n, k, sum_cnt;
int res[10];
bool flag = true;

void plus_123(int idx, int sum){
    if(!flag || sum > n){ return; }
    if(sum == n){
        sum_cnt++;
        if(sum_cnt == k){
            flag = false;
            for(int i=0; i<idx - 1; i++){
                cout << res[i] << '+';
            }
            cout << res[idx-1];
        }
        return;
    }

    for(int i=1; i<=3; i++){
        res[idx] = i;
        plus_123(idx + 1, sum + i);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    for(int i=1; i<=3; i++){
        res[0] = i;
        plus_123(1, i);
    }

    if(flag) { cout << -1; }
    return 0;
}