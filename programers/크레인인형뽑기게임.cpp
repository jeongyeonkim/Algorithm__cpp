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
                pushNum = board[j][moves[i]-1];
                board[j][moves[i]-1] = 0;
                break;
            }
        }
        if(pushNum == -1){ continue; }
        if(result.empty()){ result.push_back(pushNum); }
        else{
            if(result.back() == pushNum){
                result.pop_back();
                cnt += 2;
            }else{
                result.push_back(pushNum);
            }
        }
    }
    answer = cnt;
    return answer;
}