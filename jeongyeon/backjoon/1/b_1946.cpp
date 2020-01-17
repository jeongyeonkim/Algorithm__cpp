// 신입 사원
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int T, N, cnt, scoreCheck;
vector<int> newcomer;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> T;

    for(int i=0; i<T; i++){
        cin >> N;
        cnt = 1;
        vector<pair<int, int> > score;

        for(int j=0; j<N; j++){
            int a,b; cin >> a >> b;
            score.push_back(make_pair(a,b));
        }

        sort(score.begin(), score.end());
        scoreCheck = score[0].second;

        for(int j=1; j<score.size(); j++){
            if(scoreCheck > score[j].second){
                cnt++;
                scoreCheck = score[j].second;
            }

        }
        newcomer.push_back(cnt);
    }

    for(int i=0; i<newcomer.size(); i++){
        cout << newcomer[i] << "\n";
    }
}