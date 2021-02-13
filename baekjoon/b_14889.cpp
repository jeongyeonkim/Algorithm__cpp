// 스타트와 링크

//조합 - > DFS 풀이 -> 52ms
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string.h>
using namespace std;
int N, result = 1e9;
int arr[21][21], check[21];
int seleted[21];
vector<int> useIdx;

void score(){
    int sum = 0, sumN = 0;;
    for(int i=0; i<N/2; i++){
        check[seleted[i]] = 1;
        for(int j=0; j<N/2; j++){
            if(i == j){ continue; }
            sum += arr[seleted[i]][seleted[j]];
        }
    }

    for(int i=1; i<=N; i++){
        if(!check[i]){ useIdx.push_back(i); }
    }

    for(int i=0; i<N/2; i++){
        for(int j=0; j<N/2; j++){
            if(i == j){ continue; }
            sumN += arr[useIdx[i]][useIdx[j]];
        }
    }
    result = min(result, abs(sum - sumN));
}

void choise(int idx, int cnt){
    if(cnt >= N/2){
        memset(check, 0, sizeof(check));
        useIdx.clear();
        score();
        return;
    }

    for(int i=idx+1; i<=N; i++){
        seleted[cnt] = i;
        choise(i, cnt + 1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){ cin >> arr[i][j]; }
    }
    choise(0, 0);
    cout << result;
    return 0;
}

// 조합 -> 비트마스크 풀이 -> 시간 더 걸림 -> 108ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int N, result = 1e9;
int arr[21][21];
vector<int> team1, team2;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){ cin >>arr[i][j]; }
    }

    for(int i=0; i<(1<<N); i++){
        team1.clear();
        team2.clear();

        for(int j=0; j<N; j++){
            if((i & (1 << j)) == 0){ team1.push_back(j); }
            else{ team2.push_back(j); }
        }

        if(team1.size() > N/2 || team2.size() > N/2){ continue; }

        int sum1 = 0, sum2 = 0;
        for(int x=0; x<N/2; x++){
            for(int y=0; y<N/2; y++){
                if(x == y){ continue; }
                sum1 += arr[team1[x]][team1[y]];
                sum2 += arr[team2[x]][team2[y]];
            }
        }

        result = min(result, abs(sum1 - sum2));
    }

    cout << result;
    return 0;
}