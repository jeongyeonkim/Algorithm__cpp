//동전2
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n, k;
int coin[101], value[10001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){ cin >> coin[i]; }
    for(int i=1; i<=k; i++){ value[i] = 10001; }

    for(int i=1; i<=n; i++){
        for(int j=coin[i]; j<=k; j++){
            value[j] = min(value[j], value[j-coin[i]] + 1);
        }
    }

    if(value[k] == 10001){
        cout << -1;
    }else{
        cout << value[k];
    }
}