// 택배
/*
현재 시점에서 일단 택배 다 태우고
현재 무게가 택배 실을 수 있는 무게를 넘었을 경우
가장 멀리있는 택배부터 빼감
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, C, M, result;

struct info{
    int start, goal, weight;
};
vector<info> arr;
int village[2001];

bool cmp(info &a, info &b){
    if(a.start < b.start){ return true; }
    else if(a.start == b.start){
        if(a.goal < b.goal){ return true; }
        else if(a.goal == b.goal){
            if(a.weight < b.weight){ return true; }
        }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> C >> M;
    for(int i=0; i<M; i++){
        int a, b, c; cin >> a >> b >> c;
        arr.push_back({a, b, c});
    }
    sort(arr.begin(), arr.end(), cmp);
    int current_weight = 0;
    int current_village = arr[0].start;
    for(int i=0; i<arr.size(); i++){
        result += village[current_village];
        current_weight -= village[current_village];
        village[current_village] = 0;

        if(current_village == arr[i].start){
            village[arr[i].goal] += arr[i].weight;
            current_weight += arr[i].weight;

            if(current_weight > C){
                for(int j=N; j>current_village; j--){
                    if(current_weight == C){ break; }
                    if(current_weight - C >= village[j]){
                        current_weight -= village[j];
                        village[j] = 0;
                    }
                    else{
                        village[j] -= current_weight - C;
                        current_weight = C;
                    }
                }
            }
        }
        else{ current_village++; i--; }
    }
    for(int i=1; i<=N; i++){ result += village[i]; }
    
    cout << result;
    return 0;
}