// 크게 만들기
#include <iostream>
#include <vector>
using namespace std;
int N, K;
int temp, NumSize;
vector<int> result;

int main(){
    // 아래 코드 있을 경우 백준에서 채점 오류남.
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    // 최종 결과 값 길이.
    NumSize = N-K;

    //첫번값으로 초기화.
    scanf("%1d", &temp);
    result.push_back(temp);

    for(int i=1; i<N; i++){
        scanf("%1d", &temp);

        // K값이 0일 경우 나머지 숫자 다 넣음
        // result에 있는 모든 값과 비교하여 큰 숫자가 첫번째 숫자가 되게 만듦 -> 최대값 출력
        while(K !=0 && !result.empty()){
            if( result.back() < temp ){
                result.pop_back();
                K--;
            }else{
                break;
            }
        }

        //이미 최대값이 넣어져 있을땐 이후 숫자 넣지 않음.
        if(result.size() != NumSize){
            result.push_back(temp);
        }
    }

    for(int i=0; i<result.size(); i++){
        cout << result[i];
    }
}