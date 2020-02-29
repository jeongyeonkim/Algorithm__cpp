// 구슬 탈출2
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, result;
int arr[11][11];
pair<int, int> red, blue;
// 남, 북, 동, 서
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int oppositeDir[4] = {1, 0, 3, 2};


int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    // 빈칸 = 0, 벽 = 1, 구멍 = -1
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char a; cin >> a;
            if(a == '#'){ arr[i][j] = 1; }
            else if(a == 'O'){ arr[i][j] = -1; }
            else if(a == 'R'){
                red.first = i;
                red.second = j;
            }else if(a == 'B'){
                blue.first = i;
                blue.second = j;
            }
        }
    }
    
    cout << result;
    return 0;
}