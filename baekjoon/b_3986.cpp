// 좋은 단어
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
int N, result;
string str;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str;
        stack<char> ch;

        for(int j=0; j<str.length(); j++){
            if(!ch.empty() &&ch.top() == str[j]){ ch.pop(); }
            else{ ch.push(str[j]); }
        }

        if(ch.empty()){ result++; }
    }

    cout << result;
    return 0;
}