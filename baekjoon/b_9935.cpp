// 문자열 폭발
// 6052KB 12ms

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string removeWord, str, boomStr;

// 1. 지워야하는 문자의 끝 단어와 현재 탐색 위치의 단어가 같으면
//      같은 단어인지 체크
// 2. 탐색 중 다른게 나오면 break > 시간 줄여주기
// 3. 같은 단어면 지우기
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> str >> removeWord;

    for(int i=0; i<str.length(); i++){
        boomStr += str[i];
        if(str[i] == removeWord[removeWord.length() - 1]){
            bool flag = true;

            for(int j=0; j<removeWord.length(); j++){
                if(removeWord[removeWord.length() - 1 - j] != boomStr[boomStr.length() - 1 - j]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                for(int z=0; z<removeWord.length(); z++){ boomStr.pop_back(); }
            }
        } 
    }
    
    if(boomStr.length() > 0){
        cout << boomStr;
    }else{
        cout << "FRULA";
    }
    return 0;
}