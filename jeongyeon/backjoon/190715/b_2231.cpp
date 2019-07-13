#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n=0, m,j=-1, w=0;
    cin >> n;
    w=n; m=n;
    while(w>0){
        w /= 10;
        j++;
    }

    for(int i=1; i<n; i++){
        w = i;
        int k = i;
        if(j>1){
            for(int a=j; a >0; a--){
                k += {w/(10^a)};
                w %= 10^a;
            }
        }
        //k += w;
        if(k == n && m > i){
            m = i;
        }
    }

    cout << m;
    return 0;
}