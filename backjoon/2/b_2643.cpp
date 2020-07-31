// 색종이 올려 놓기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, result;
vector<pair <int, int> > colored_paper;
int dp[101];

bool cmp(const pair<int, int> a, const pair<int,int> b){
    if(a.first < b.first){ return true; }
    else if(a.first == b.first){
        if(a.second < b.second){ return true; }
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    int input1, input2;
    for(int i=0; i<N; i++){
        cin >> input1 >> input2;
        if(input1 > input2){
            colored_paper.push_back(make_pair(input1, input2));
        }else{
            colored_paper.push_back(make_pair(input2, input1));
        }
    }
    sort(colored_paper.begin(), colored_paper.end(), cmp);

    dp[0] = 1;
    for(int i=1; i<N; i++){
        for(int j=0; j<N; j++){
            if(i == j){ continue; }
            if(colored_paper[i].first >= colored_paper[j].first && colored_paper[i].second >= colored_paper[j].second){
                dp[i] = max(dp[i], dp[j]);
            }
        }
        result = max(result, ++dp[i]);
    }

    cout << result;
    return 0;
}