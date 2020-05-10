#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int dir[12][2] = {{3, 1}, {0, 0}, {0, 1}, {0,2}, {1, 0}, {1, 1}, {1,2}, {2, 0}, {2, 1}, {2, 2}, {3, 0}, {3, 2}};
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int l = 10, r = 11;

struct info{
    int x, y, d;
};

int sol(int idx, int goal){
    int res = 0;
    queue<info> que;
    que.push({dir[idx][0], dir[idx][1], 0});

    while (!que.empty()){
        int x = que.front().x;
        int y = que.front().y;
        int cnt = que.front().d;
        que.pop();

        if(x == dir[goal][0] && y == dir[goal][1]){
            res = cnt;
            break;
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 3){ continue; }
            que.push({nx, ny, cnt + 1});
        }
    }
    return res;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    for(int i=0; i<numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer += "L";
            l = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer += "R";
            r = numbers[i];
        }
        else{
            int l_d = sol(l, numbers[i]), r_d = sol(r, numbers[i]);
            if(l_d == r_d){
                if(hand.compare("left") == 0){
                    answer += "L";
                    l = numbers[i];
                }else{
                    answer += "R";
                    r = numbers[i];
                }
            }else{
                if(l_d > r_d){
                    answer += "R";
                    r = numbers[i];
                }else{
                    answer += "L";
                    l = numbers[i];
                }
            }
        }
    }
    return answer;
}