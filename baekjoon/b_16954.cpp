// 움직이는 미로 탈출
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int arr[9][9], result;
string str;
int dx[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int dy[9] = {1, 0, -1, 0, -1, 1, -1, 1, 0};

struct info{
    int x, y;
};
queue<info> Q;

void moveWall(){
    for(int i=7; i>=0; i--){
    	for(int j=0; j<8; j++){
    		if(arr[i][j] == 1){
    			arr[i][j] = 0;
    			arr[i+1][j] = 1;
    		}
    	}
    }
    queue<info> temp;
    while(!Q.empty()){
    	if(arr[Q.front().x][Q.front().y] == 0){
    		temp.push({Q.front().x, Q.front().y});
    	}
    	Q.pop();
    }
    Q = temp;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i=0; i<8; i++){
        cin >> str;
        for(int j=0; j<8; j++){
            if(str[j] == '#'){ arr[i][j] = 1; }
        }
    }
    Q.push({7, 0});
    
    while(true){
    	if(Q.empty()){ break; }
    	bool flag = false;
    	queue<info> que;
    	que = Q;
    	while(!Q.empty()){ Q.pop(); }
    	
    	while(!que.empty()){
	    	int x = que.front().x;
	    	int y = que.front().y;
	    	que.pop();
	    	
	    	if(x == 0 && y == 7){
	    		result = 1;
	    		flag = true;
	    		break;
	    	}
	    	
	    	for(int i=0; i<9; i++){
	    		int nx = x + dx[i];
	    		int ny = y + dy[i];
	    		if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || arr[nx][ny] == 1){ continue; }
	    		Q.push({nx, ny});
	    	}
    	}
    	if(flag){ break; }
    	moveWall();
    }
    cout << result;
    return 0;
}