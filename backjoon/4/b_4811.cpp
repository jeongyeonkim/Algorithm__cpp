// 알약
#include <iostream>
#include <string.h>
using namespace std;
int n;
long long medicine[31][31];

// 한개  반개
// -1   +1
//  0   -1
long long changePill(int pill, int half){
    if(pill == 0){ return 1; }
    if(medicine[pill][half] != -1 ){ return medicine[pill][half]; }

    medicine[pill][half] = changePill(pill -1, half + 1);
    if(half > 0){ medicine[pill][half] += changePill(pill, half - 1); }

    return medicine[pill][half];
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(medicine, -1, sizeof(medicine));

    while (true){
        cin >> n;
        if(n == 0){ break; }
        cout << changePill(n, 0) << "\n";
    }
    return 0;
}