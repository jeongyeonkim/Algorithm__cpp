// 컬러볼
// 투포인터로 풀기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, C, S;
int result[200001];
vector<pair <int, int> > colorBoll;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N;
    vector<int> arr[N + 1];
    for(int i=0; i<N; i++){
        cin >> C >> S;
        colorBoll.push_back(make_pair(C, S));
        arr[C].push_back(S);
    }
    //for(int i=1; i<=N; i++){ sort(arr[i].begin(), arr[i].end()); }
    for(int i=0; i<N; i++){
        for(int j=1; j<=N; j++){
            if(j == colorBoll[i].first){ continue; }
            for(int z=0; z<arr[j].size(); z++){
                if(arr[j][z] >= colorBoll[i].second){ continue; }
                result[i] += arr[j][z];
            }
        }
    }

    for(int i=0; i<N; i++){ cout << result[i] << "\n"; }
    return 0;
}