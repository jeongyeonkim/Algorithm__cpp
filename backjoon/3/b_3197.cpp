// 백조의 호수
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int R, C;
string str;
vector<pair<int, int>> swan;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int arr[1501][1501];


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> str;
        for(int j=0; j<C; j++){
            if(str[j] == 'L'){ swan.push_back(make_pair(i, j)); }
            else if(str[j] == 'X'){ arr[i][j] = 1;}
        }
    }

}