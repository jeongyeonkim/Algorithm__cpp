#include <string>
#include <vector>
using namespace std;
vector<int> result;
int cnt;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for(int i=0; i<moves.size(); i++){
        int pushNum = -1;
        
        for(int j= 0; j<board.size(); j++){
            if(board[j][moves[i]-1]){
                pushNum = board[j][moves[i]-1]; // 해당 위치에 상위 인형 num 저장
                board[j][moves[i]-1] = 0; // 최상위 리셋
                break;
            }
        }
        if(pushNum == -1){ continue; } // 해당 위치에 인형이 하나도 없을 경우 continue
        if(result.empty()){ result.push_back(pushNum); }
        else{ // 같은 번호가 있을 경우 사라지는 부분
            if(result.back() == pushNum){ // 같은 번호의 인형은 2개 이상 있을 수 없음 -> 한 개만 있어도 터지기 때문에
                result.pop_back(); // 같은 번호일 경우 숫자 빼기
                cnt += 2;
            }else{
                result.push_back(pushNum);
            }
        }
    }
    answer = cnt;
    return answer;
}