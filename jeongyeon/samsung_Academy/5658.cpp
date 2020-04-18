// [모의 SW 역량테스트] 보물상자 비밀번호
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;
int test_case, T, N, K;
deque<char> arr;
int result, maxNum;
vector<string> num;

bool cmp(string a, string b){ return a>b; }

void Decimal(string a){
    for(int i=0; i<(N/4); i++){
        int tempNum = a.at(i) - '0';
        if(tempNum >= 17 && tempNum <= 22){ // A ~ F 값 정수 변환
            tempNum -= 7;
        }

        result += (int)pow(16, (N/4)-1-i)*tempNum;
    }
}

void changeDecimal(){
    int t = N/4;
    for(int i=0; i<N;){ // 4등분한 숫자 num에 넣기
        string temp;
        for(int j=0; j<t; j++){
            temp += arr[i+j];
        }
        num.push_back(temp);
        i += t;
    }
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N >> K;
        for(int i=0; i<N; i++){
            char a; cin >> a;
            arr.push_back(a);
        }

        for(int i=0; i<(N/4); i++){
            changeDecimal();

            arr.push_front(arr.back());
            arr.pop_back();
        }
        sort(num.begin(), num.end()); // 오름차순 정렬
        num.erase(unique(num.begin(), num.end()), num.end()); // 중복 제거
        sort(num.begin(), num.end(), cmp); // 내림차순 정렬
        
        Decimal(num[K-1]); // K번째 값 16진수 10진수로 정수 변환

        cout << "#" << test_case << " " << result << "\n"; 
        arr.clear(); num.clear();
        maxNum = 0; result = 0;
    }
    return 0;
}