#include <iostream>
#include <string>
#include <vector>
using namespace std;
int visited[201];
vector<vector<int>> arr; // 입력값

void network(int node){ // DFS
    visited[node] = 1;
    
    for(int i=0; i<arr[node].size(); i++){
        if(!visited[i] && arr[node][i] == 1){ // 방문 안했고, 존재할 때
            network(i);
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    arr = computers;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            network(i);
            answer++;
        }
    }

    return answer;
}