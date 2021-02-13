// 팰린드롬 만들기
#include <iostream>
#include <string>
using namespace std;
string str;
int result = 1, pos, _left, _right;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str;
    pos = str.length() / 2;
    if(str.length() % 2 == 0){
        while (pos < str.length()){
            bool flag = true;
            _right = pos; _left = pos - 1;
            while (true){
                if(_left < 0 || _right >= str.length()){ break; }
                if(str[_right] != str[_left]){
                    if(_right == str.length() - 1){
                        result = pos * 2 + 1;
                    }
                    flag = false;
                    break;
                }
                _right++; _left--;
            }
            if(flag){
                result = (pos + 1) * 2;
            }
            pos++;
        }
    }
    else{
        while (pos < str.length()){
            _left = _right = pos;
            bool flag = true;
            while (true){
                _left--; _right++;
                if(_left < 0 || _right >= str.length()){ break; }
                if(str[_left] != str[_right]){
                    flag = false;
                    break;
                }
            }
        
            if(flag){
                result = pos * 2 + 1;
                break;
            }
            pos++;
        }
    }

    cout << result;
    return 0;
}