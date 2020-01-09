#include <iostream>
using namespace std;
int n, k;
int coin[101], value[10001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    value[0]=1;
    for(int i=1; i<=n; i++){
        cin >> coin[i];
        for(int j=coin[i]; j<=k; j++){
            value[j] += value[j-coin[i]];
        }
    }
    cout << value[k];
}