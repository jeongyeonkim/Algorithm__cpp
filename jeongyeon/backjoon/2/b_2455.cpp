//지능형 기차
#include <iostream>
#include <algorithm>
using namespace std;
int train[4][2], peopleMax, temp;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=1; i<=4; i++){ cin >> train[i][0] >> train[i][1]; }

    for(int i=1; i<=4; i++){
        temp -= train[i][0];
        peopleMax = max(peopleMax, temp);
        temp += train[i][1];
        peopleMax = max(peopleMax, temp);
    }

    cout << peopleMax;
}