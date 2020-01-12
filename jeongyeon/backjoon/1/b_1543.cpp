//문서 검색
#include <iostream>
#include <string>
using namespace std;
string input, Search;
int cnt;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // 공백 포함 읽기라서 한 줄씩 입력 받음.
    getline(cin, input);
    getline(cin, Search);

    for(int i=0; i<input.length(); i++){
        // 첫번째 문자 일치
        if(input[i] == Search[0]){
            // 첫번째 이후 문자 일치 불일치 판단을 위해 check 사용.
            bool check = true;
            for(int j=1; j<Search.length(); j++){
                // 이후 문자 불일치 시 check는 false.
                if(input[j+i] != Search[j]){ check = false; }
            }
            // 이후 문자 일치 시 카운트++
            // 일치 이후 부터 다시 체크 시작.
            if(check){
                cnt++;
                i += Search.size()-1;
            }
        }
    }

    cout << cnt;
}