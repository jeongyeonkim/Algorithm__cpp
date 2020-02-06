// 로또
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int k;
int arr[14], lotto[6];

void nextLotto(int i, int idx){
    if(idx == 6){
        for(int j=0; j<6; j++){
            cout << lotto[j] << " ";
        }
        cout << "\n";
        return;
    }


    for(int j=i; j<k; j++){
        lotto[idx] = arr[j];
        nextLotto(j+1, idx+1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (1){
        cin >> k;
        if(k == 0){ break; }

        for(int i=0; i<k; i++){ cin >> arr[i];}

        nextLotto(0, 0);
        cout << "\n";   
    }
    return 0;
}