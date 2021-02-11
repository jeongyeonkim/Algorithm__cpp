// 거북이
/*

    시뮬레이션
1. 거북이가 이동한 좌표의 최대 최소값 저장
2. (최대X - 최소X) * (최대Y - 최소Y) = 결과
3. (0, 0)에서 시작한다고 하였지만, 음수 처리 절대값 씌워주기 싫어서 (500, 500)에서 시작
4. dir = 동, 남, 서, 북
5. L 90도 회전은 (현재 방향에서 - 1)
6. R 90도 회전은 (현재 방향에서 + 1)
7. dir 음수처리를 위해 % 사용

*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int T, dir, x, y;
int minX, minY, maxX, maxY;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string input;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while (T--){
        cin >> input;
        minX = minY = 500;
        maxX = maxY = 500;
        x = y = 500;
        dir = 3;

        for(int i=0; i<input.length(); i++){
            if(input[i] == 'F'){
                x += dx[dir]; y += dy[dir];
            }
            else if(input[i] == 'B'){
                x += (-1)*dx[dir]; y += (-1)*dy[dir];
            }
            else if(input[i] == 'L'){
                dir = (dir + 3) % 4;
            }
            else if(input[i] == 'R'){
                dir = (dir + 1) % 4;
            }

            minX = min(minX, x);
            minY = min(minY, y);
            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }
    
        cout << (maxX - minX) * (maxY - minY) << "\n";
    }
    
}