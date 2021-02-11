#include <iostream>
#include <deque>
using namespace std;
int N, K, input, result;
deque<int> durabilityOfBelt;
deque<bool> existOfLobot;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> K;

    for(int i=0; i<2*N; i++){
        cin >> input;
        durabilityOfBelt.push_back(input);
        existOfLobot.push_back(false);
        if(input == 0){
            K--;
        }
    }

    while (K > 0){
        result++;

        // 1. 벨트가 한 칸 회전
        durabilityOfBelt.push_front(durabilityOfBelt.back());
        durabilityOfBelt.pop_back();
        existOfLobot.push_front(existOfLobot.back());
        existOfLobot.pop_back();
        if(existOfLobot[N-1]){
            existOfLobot[N-1] = false;
        }

        // 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동
        for(int i = N-2; i>=0; i--){
            if(existOfLobot[i] && durabilityOfBelt[i+1] >= 1 && !existOfLobot[i+1]){
                existOfLobot[i] = false;
                durabilityOfBelt[i+1]--;
                if(durabilityOfBelt[i+1] <= 0){
                    K--;
                }

                if(i == N - 2){ continue; }
                existOfLobot[i+1] = true;
            }
        }

        // 3.올라가는 위치에 로봇이 없다면 로봇을 하나 올림
        if(!existOfLobot[0] && durabilityOfBelt[0] > 0){
            existOfLobot[0] = true;
            durabilityOfBelt[0]--;
            if(durabilityOfBelt[0] <= 0){
                    K--;
            }
        }
    }
    
    cout << result; 
    return 0;
}