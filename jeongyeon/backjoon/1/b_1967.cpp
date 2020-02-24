// 트리의 지름
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 10001
using namespace std;
int n, p, c, weight;
vector<pair <int, int> > arr[MAX];
int visited[MAX];
int firstNode, firstSum;

void treeDiameter(int start, int sum){
    visited[start] = 1;

    if(sum > firstSum){
        firstNode = start;
        firstSum = sum;
    }

    for(int i=0; i<arr[start].size(); i++){
        if(visited[arr[start][i].first] == 0){
            treeDiameter(arr[start][i].first, sum + arr[start][i].second);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n-1; i++){
        cin >> p >> c >> weight;
        arr[p].push_back(make_pair(c, weight));
        arr[c].push_back(make_pair(p, weight));
    }

    // root 노드에서 가장 먼 하위 노드 찾기 = firstNode
    treeDiameter(1, 0);
    memset(visited, 0, sizeof(visited));
    // 가장 먼 노드에서 가장 먼 하위 노드 찾기
    treeDiameter(firstNode, 0);

    cout << firstSum;
    return 0;
}