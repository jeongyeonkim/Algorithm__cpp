#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int result, weakSize, distSize, temp;
vector<int> weakCopy, distCopy;
int visited[16], useDist[9];

void wall(int x, int cnt){
    if(x == weakSize){
        result = min(result, cnt);
        return;
    }
    if(cnt >= distSize || cnt >= result){ return; }

    int visitedCopy[16];
    for(int i=0; i<weakSize; i++){ visitedCopy[i] = visited[i]; } // 방문 복사

    for(int i=0; i<distSize; i++){
        if(useDist[i]){ continue; }
        int idx = weakCopy[x];
        int endIdx = weakCopy[x] + distCopy[i];
        int next = 0, sum = 0;
        useDist[i] = 1;
        memcpy(visited, visitedCopy, sizeof(visited));
        
        for(int j=x; j<weakSize; j++){
            if(visited[j] == 0 && weakCopy[j] <= endIdx){
                visited[j] = 1;
                sum++;
            }else{ break; }
        }
        if(sum != 0){ wall(x + sum, cnt + 1); }
        useDist[i] = 0;
    }
}

bool cmp(int a, int b){ return a > b; }

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    result = dist.size() + 1;
    weakSize = weak.size();
    distSize = dist.size();
    sort(dist.begin(), dist.end(), cmp); // 범위 넣은 애들부터
    weakCopy = weak; distCopy = dist;
    if(dist[0] >= n){ return 1; } // 제일 큰 수로 모든 취약점 방문 가능할 경우

    for(int i=0; i<weak.size(); i++){
        memset(visited, 0, sizeof(visited));
        wall(0, 0);
        temp = weakCopy[0] + n; // 시작점 바꿔주기 위해서 취약점 한칸씩 당김
        for(int j=1; j<weak.size(); j++){ weakCopy[j-1] = weakCopy[j]; }
        weakCopy[weak.size()-1] = temp;
    }

    if(result == dist.size() + 1){ answer = -1; }
    else{ answer = result; }
    return answer;
}