#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n=0, m =0,j=-1, w=0;
    cin >> n;
    w=n;
    while(w>0){
        w /= 10;
        j++;
    }
    for(int i=1; i<n; i++){
        w = i;
        int k = i;
        for(int a=j; a>=0; --a){
            k += w/pow(10,a);
            w %= (int)pow(10,a);
        }
        if(k == n){
            m = i;
            break;
        }
    }
    cout << m;
    return 0;
}