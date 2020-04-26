// X보다 작은 수
#include <iostream>
using namespace std;
int N, X;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> X;
    for(int i=0; i<N; i++){
        int a = 0;
        cin >> a;
        if(a < X){ cout << a << " "; }
    }
}