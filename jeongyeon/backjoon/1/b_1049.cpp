// 기타줄
#include <iostream>
using namespace std;
int N, M, result=6000, result2=6000;
int pack=1000, piece=1000;
int rest, quotient;

// 고장난 기타줄의 개수를 6으로 나눠 6개 구매했을때 패키지 값과 낱개*6 중 작은 값 result에 저장.
// 6으로 나눈 나머지를 a라 한다면, 낱개*a 와 패키지 전체 값 중 작은 값 result2에 저장.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;

    if(N>=6){
        quotient = N/6;
        rest = N%6;
    }else{
        quotient = 0;
        rest = N;
    }

    for(int i=0; i<M; i++){
        cin >> pack >> piece;
        result = min(result, min(pack, piece*6));
        result2 = min(result2, min(pack, piece*rest));
    }

    cout << result*quotient + result2;
}