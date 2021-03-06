// 가스관
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std; 
int R, C;
char pipeMap[26][26];
int visited[26][26];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
map<char, vector<int> > pipe;

// 1. 파이프가 있는 곳에 가능한 방향으로 이동해서 방문 체크하기
// 2. 방문 체크 시 들어온 방향을 저장해야함 >> 비트마스킹 사용
//          오른쪽 > 0001
//          아래 > 0010
//          왼쪽 > 0100
//          위 > 1000
// 3. 방문 했는데 파이프가 없는 곳이 파이프를 넣어야 하는 곳
// 4. 방문 값이 파이프를 못만드는 경우 상하좌우에 M or Z 존재
// 5. 4번의 경우 M or Z 방향 값 더하기
bool printResult(int value){
    if(value == 10){ cout << "|"; }
    else if(value == 5){ cout << "-"; }
    else if(value == 15){ cout << "+"; }
    else if(value == 3){ cout << "1"; }
    else if(value == 9){ cout << "2"; }
    else if(value == 12){ cout << "3"; }
    else if(value == 6){ cout << "4"; }
    else { return false; }
    return true;
}

void pipeFlowChecked(int x, int y){
    vector<int> dir = pipe[pipeMap[x][y]];

    for(int i=0; i<dir.size(); i++){
        int nx = x + dx[dir[i]];
        int ny = y + dy[dir[i]];
        if(nx < 0 || ny < 0 || nx >= R || ny >= C){ continue; }

        visited[nx][ny] += 1 << ((dir[i] + 2) % 4);
    }
}

void setValue(){
    vector<int> _value;
    _value.push_back(1); _value.push_back(3);
    pipe.insert(make_pair('|', _value)); _value.clear();
    _value.push_back(0); _value.push_back(2);
    pipe.insert(make_pair('-', _value)); _value.clear();
    _value.push_back(0); _value.push_back(1); _value.push_back(2); _value.push_back(3);
    pipe.insert(make_pair('+', _value)); _value.clear();
    _value.push_back(0); _value.push_back(1);
    pipe.insert(make_pair('1', _value)); _value.clear();
    _value.push_back(0); _value.push_back(3);
    pipe.insert(make_pair('2', _value)); _value.clear();
    _value.push_back(2); _value.push_back(3);
    pipe.insert(make_pair('3', _value)); _value.clear();
    _value.push_back(1); _value.push_back(2);
    pipe.insert(make_pair('4', _value));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    setValue();
    for(int i=0; i<R; i++){
        string str; cin >> str;
        for(int j=0; j<C; j++){
            pipeMap[i][j] = str[j];
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(pipeMap[i][j] == 'M' || pipeMap[i][j] == 'Z') {
                visited[i][j] = 16;
            } else if(pipeMap[i][j] != '.'){
                pipeFlowChecked(i, j);
            }
        }
    }
 
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(visited[i][j] != 0 && pipeMap[i][j] == '.'){
                cout << i + 1 << " " << j + 1 << " ";
                if(!printResult(visited[i][j])){
                    for(int d=0; d<4; d++){
                        int ni = i + dx[d];
                        int nj = j + dy[d];
                        if(ni < 0 || nj < 0 || ni >= R || nj >= C) { continue; }
                        if(pipeMap[ni][nj] == 'M' || pipeMap[ni][nj] == 'Z'){
                            visited[i][j] += 1 << d;
                            printResult(visited[i][j]);
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}