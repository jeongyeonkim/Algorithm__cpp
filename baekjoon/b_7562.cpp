// 나이트의 이동
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int test_case, I, x1, x2, y1, y2;
int arr[301][301];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void moveNight(){
    queue<pair <int, int> > night;
    night.push(make_pair(x1, y1));

    while (!night.empty()){
        int x = night.front().first;
        int y = night.front().second;
        night.pop();

        if(x == x2 && y == y2){
            cout << arr[x][y] << "\n";
            return;
        }

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= I || ny >= I){ continue; }
            if(arr[nx][ny]) { continue; }

            arr[nx][ny] = arr[x][y] + 1;
            night.push(make_pair(nx, ny));
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> test_case;

    while(test_case--){
        cin >> I;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        memset(arr, 0, sizeof(arr));
        moveNight();
    }
    return 0;
}