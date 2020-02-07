//  [SW Test 샘플문제] 프로세서 연결하기
#include<iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int test_case, T, N;
int minWire, maxCore;
int arr[12][12], visited[12][12];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int> > core;

void Processor(int start, int line, int c){
    //전체 코어 갯수 까지 탐색 했을 경우
    if(start == core.size()){
        if(maxCore < c){
            maxCore = c;
            minWire = line;
        }else if(maxCore == c && minWire > line){ minWire = line; }
        return;
    }

    int x = core[start].first;
    int y = core[start].second;

    int temp[12][12];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ temp[i][j] = visited[i][j]; }
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        bool check = true;
        int temp_line = 0;
        
        while(true){
            if(nx < 0 || ny < 0 || nx >= N || ny >= N){ break; }
            if(arr[nx][ny] == 1 || visited[nx][ny] == 1){ check = false; break; }

            visited[nx][ny] = 1;
            nx += dx[i];
            ny += dy[i];
            temp_line++;
        }

        if(check){ Processor(start+1, line + temp_line, c+1); }

        if(temp_line > 0){
            for(int a=0; a<N; a++){
                for(int b=0; b<N; b++){ visited[a][b] = temp[a][b]; }
            }
        }
    }

    Processor(start+1, line, c);
}
int main(int argc, char** argv){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 1){
                    // 테두리에 있는 core는 이미 연결되어 있기 때문에 탐색 필요 없음.
                    if(i == 0 || j == 0 || i == N-1 || j == N-1){ continue; }
                    core.push_back(make_pair(i,j));
                }
            }
        }
        Processor(0, 0, 0);
        cout << "#" << test_case << " " << minWire << "\n";

        memset(arr, 0 ,sizeof(arr));
        memset(visited, 0, sizeof(visited));
        minWire = 0;
        maxCore = 0;
        core.clear();
    }
	return 0;
}
