#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string, int> arr;
double inter, combin; // 교집합, 합집합 수

bool checkbound(string str){
    if(str[0] < 'a' || str[0] > 'z'){ return false; }
    if(str[1] < 'a' || str[1] > 'z'){ return false; }
    return true;
}

string lowerWord(string str){ // 대문자 -> 소문자 변환
    string res = "";
    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            res += str[i] - 'A' + 'a';
        }
        else{ res += str[i]; }
    }
    return res;
}

int solution(string str1, string str2) {
    int answer = 0;
    str1 = lowerWord(str1);
    str2 = lowerWord(str2);

    for(int i=0; i<str1.length()-1; i++){
        string temp = str1.substr(i, 2);
        if(!checkbound(temp)){ continue; }

        if(arr.find(temp) == arr.end()){
            arr.insert(make_pair(temp, 1));
        }
        else{ arr[temp]++; }
        combin++;
    }

    for(int i=0; i<str2.length()-1; i++){
        string temp = str2.substr(i, 2);
        if(!checkbound(temp)){ continue; }

        if(arr.find(temp) == arr.end()){ combin++; } // 교집합이 아니면 합집합 수 ++
        else{
            if(arr[temp] > 0){ // 교집합일 경우
                inter++;
                arr[temp]--;
            }else{ combin++; } // 같은 문자라도 str2가 갖고있는 수가 더 클 경우
        }
    }
    if(combin == 0){ answer = 65536; } // 0으로 나눌 수 없으면 inter / comnin = 1
    else{ answer = (inter / combin) * 65536; }
    return answer;
}


// multiset STL 사용 풀이
#include <iostream>
#include <string>
#include <set>
using namespace std;
double inter, combin; // 교집합, 합집합 수

bool check(char ch){
    return ch >= 'a' && ch <= 'z';
}

multiset<string> split(string str){
    multiset<string> arr;

    for(int i=0; i<str.length()-1; i++){
        if(!check(str[i]) || !check(str[i+1])){ continue; }
        string temp = str.substr(i, 2);
        arr.insert(temp);
    }

    return arr;
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    multiset<string> _str1 = split(str1);
    multiset<string> _str2 = split(str2);

    

    return answer;
}