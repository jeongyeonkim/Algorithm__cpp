// 십자뒤집기
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
int P, result, input;
int visited[1<<10];
string str;
vector<int> turnOver[9] = {{0, 1, 3}, {0, 1, 2, 4}, {1, 2, 5}, {0, 3, 4, 6}, {1, 3, 4, 5, 7}, {2, 4, 5, 8}, {3, 6, 7}, {4, 6, 7, 8}, {5, 7, 8}};

void runTurn(){
    queue<int> que;
    que.push(input);
    visited[input] = 1;

    while (!que.empty()){
        int queSize = que.size();

        while (queSize--){
            int x = que.front();
            que.pop();

            if(x == 0){ return; }

            for(int i=0; i<9; i++){
                int temp = x;
                for(int j=0; j<turnOver[i].size(); j++){
                    temp ^= (1 << turnOver[i][j]);
                }

                if(visited[temp] == 0){
                    visited[temp] = 1;
                    que.push(temp);
                }
            }
        }
        result++;
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> P;
    while (P--){
        result = 0;
        memset(visited, 0, sizeof(visited));
        input = 0;
        for(int i=0; i<3; i++){
            cin >> str;
            for(int j=0; j<3; j++){
                if(str[j] == '*'){
                    input |= (1 << ((3 * i) + j));
                }
            }
        }
        runTurn();
        cout << result;
    }
    

}