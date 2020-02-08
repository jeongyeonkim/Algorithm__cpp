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

bool ASC(string a, string b){
    return a>b;
}

void Decimal(string a){
    for(int i=0; i<(N/4); i++){
        char temp = a.at(i);
        int tempNum = 0;
        if(temp == 'A'){ tempNum = 10; }
        else if(temp == 'B'){ tempNum = 11; }
        else if(temp == 'C'){ tempNum = 12; }
        else if(temp == 'D'){ tempNum = 13; }
        else if(temp == 'E'){ tempNum = 14; }
        else if(temp == 'F'){ tempNum = 15; }
        else{ tempNum = temp - '0'; }

        result += (int)pow(16, (N/4)-1-i)*tempNum;
    }
}

void changeDecimal(){
    int t = N/4;
    for(int i=0; i<N;){
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
        sort(num.begin(), num.end());
        num.erase(unique(num.begin(), num.end()), num.end());
        sort(num.begin(), num.end(), ASC);
        
        Decimal(num[K-1]);

        cout << "#" << test_case << " " << result << "\n"; 
        arr.clear();
        num.clear();
        maxNum = 0;
        result = 0;
    }
    return 0;
}