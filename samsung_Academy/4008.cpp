// [모의 SW 역량테스트] 숫자 만들기
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int test_case, T, N, calCnt;
int oper[13]; // 0 = +, 1 = -, 2 = *, 3 = /
int num[14];
int resultMax, resultMin;
vector<int> useOper;

void calculation(){
    int res = num[0];

    for(int i=0; i<useOper.size(); i++){
        if(useOper[i] == 0){ res += num[i+1]; }
        else if(useOper[i] == 1){ res -= num[i+1]; }
        if(num[i] == 0){ continue; } // 0을 나누거나 곱할 경우
        else if(useOper[i] == 2){ res *= num[i+1]; }
        else if(useOper[i] == 3){ res /= num[i+1]; }
    }

    if(res > resultMax){ resultMax = res; }
    if(res < resultMin){ resultMin = res; }
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        resultMax = (-1)*1e9; resultMin = 1e9;
        for(int i=0; i<4; i++){
            cin >> calCnt;
            while (calCnt--){ useOper.push_back(i); } // 사용 가능한 사칙연산들 다 벡터에 넣음
        }
        for(int i=0; i<N; i++){ cin >> num[i]; }

        do{ // 사칙연산 조합
            calculation();
        } while (next_permutation(useOper.begin(), useOper.end()));
        

        cout << "#" << test_case << " " << resultMax - resultMin << "\n";
        memset(oper, 0, sizeof(oper));
        memset(num, 0, sizeof(num));
        useOper.clear();
    }
    return 0;
}