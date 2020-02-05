// 토너먼트
#include <iostream>
#include <vector>
using namespace std;
int N, kim, lim, cnt;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> kim >> lim;
    if(N < kim || N < lim){ cnt = -1; }
    else{
        while(kim != lim){
            kim = (kim + 1)/2;
            lim = (lim + 1)/2;
            cnt++;
        }
    }
    cout << cnt;
}