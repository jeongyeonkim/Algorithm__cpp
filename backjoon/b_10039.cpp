// 평균 점수
#include <iostream>
using namespace std;
int result;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<5; i++){
        int input = 0;
        cin >> input;
        if(input >= 40){ result += input; }
        else{ result += 40; }
    }
    cout << result/5;
}