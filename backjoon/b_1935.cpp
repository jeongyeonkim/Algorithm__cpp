// 후위 표기식2
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int N;
string str;
double alpabat[26];
stack<double> arr;
double tmp1, tmp2;

bool tempNum(){
    if(arr.size() >= 2){
        tmp1 = arr.top();
        arr.pop();
        tmp2 = arr.top();
        arr.pop();
        return true;
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    cin >> str;
    for(int i=0; i<N; i++){ cin >> alpabat[i]; }
    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            arr.push(alpabat[str[i] - 'A']);
            continue;
        }
        bool check = tempNum();
        if(str[i] == '+'){
            if(check){ arr.push(tmp1 + tmp2); }
        }else if(str[i] == '-'){
            if(check){ arr.push(tmp2 - tmp1); }
        }else if(str[i] == '*'){
            if(check){ arr.push(tmp1 * tmp2); }
        }else if(str[i] == '/'){
            if(check){ arr.push(tmp2 / tmp1); }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << arr.top();

    return 0;
}