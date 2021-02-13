// 점수 계산
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int input, sum;
vector<pair <int, int> > score;
vector<int> idx;

bool scoreSort(const pair<int, int> a, const pair<int ,int> b){
    if(a.second > b.second){ return true; }
    else return false;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=0; i<8; i++){
        cin >> input;
        score.push_back(make_pair(i, input));
    }

    sort(score.begin(), score.end(), scoreSort);
    for(int i=0; i<5; i++){
        sum += score[i].second;
        idx.push_back(score[i].first);
    }
    sort(idx.begin(), idx.end());

    cout << sum << "\n";
    for(int i=0; i<5; i++){ cout << idx[i]+1 << " "; }
    return 0;
}