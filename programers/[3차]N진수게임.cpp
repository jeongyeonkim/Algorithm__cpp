#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
string answer;
queue<char> num;

void game(int cnt, int n){ // 진수 변환 함수(재귀로 구현)
    int r;

    r = cnt % n;
    cnt /= n;
    if(cnt > 0){ game(cnt, n); }

    if(r < 10){ num.push(r + '0'); }
    else{
        char c = r - 10 + 'A';
        num.push(c);
    }
}


string solution(int n, int t, int m, int p) {
    int cnt = 1, idx = 0;
    p--;
    num.push('0');

    while (true){
        if(answer.length() >= t){ break; } // 이미 답이 나오면 break

        game(cnt, n); // 숫자 진수 변환
        while (true){
            if(answer.length() >= t || num.empty()){ break; }
            if(idx == p){ answer += num.front(); } // 진수 변환 후 튜브의 순서와 인덱스가 같을 경우 answer에 넣어주기
            num.pop(); // 튜브 순서와 상관 없이 값 빼주기
            idx++;
            idx %= m;
        }
        
        cnt++;
    }
    
    return answer;
}