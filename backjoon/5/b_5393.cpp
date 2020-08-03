// 키로거
/*
  1. 덱 사용
  2. 현재 커서 위치 idx에 저장
  3. 삽입 삭제 deque insert, erase 사용
*/
#include <iostream>
#include <string>
#include <stack>
#include <deque>
using namespace std;
int T, idx;
string str;
deque<char> arr;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> str;
        idx = 0;
        for(int i=0; i<str.length(); i++){
            if(str[i] == '<'){
                if(idx != 0){ idx--; } // 커서 index 음수 나오면 안돼
            }
            else if(str[i] == '>'){
                if(idx < arr.size()){ idx++; } // 커서 index 덱 사이즈 넘어서면 안돼
            }
            else if(str[i] == '-'){
                if(arr.empty() || idx == 0){ continue; } // 덱 비워져있는지, idx - 1 음수 나오지 않는지 확인
                if(idx == arr.size()){ arr.pop_back(); }
                else{ arr.erase(arr.begin() + idx - 1); }
                idx--;
            }
            else{
                if(idx == arr.size()){ arr.push_back(str[i]); }
                else{ arr.insert( arr.begin() + idx, str[i]); }
                idx++;
            }
        }

        while (!arr.empty()){ // 비밀번호 출력
            cout << arr.front();
            arr.pop_front(); // 출력한 뒤 지워주기 때문에 다른 테스트케이스가 들어와도 비워줄 필요 x
        }
        cout << "\n";
    }
    return 0;
}