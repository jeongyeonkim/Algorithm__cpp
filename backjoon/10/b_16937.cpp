// 두 스티커
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int H, W, N, result;
vector<pair <int, int> > sticker;

void put(int i, int j){
    int x1 = sticker[i].first, y1 = sticker[i].second;
    int x2 = sticker[j].first, y2 = sticker[j].second;
    bool flag = false;

    for(int k=0; k<2; k++){
        for(int t=0; t<2; t++){
            if(x1 + x2 <= H && y1 <= W && y2 <= W){ flag = true; }
            else if(x1 <= H && x2 <= H && y1 + y2 <= W){ flag = true; }
            swap(x2, y2);
        }
        
        swap(H, W);
    }
    
    if(flag){
        result = max(result,  sticker[i].first*sticker[i].second + sticker[j].first*sticker[j].second);
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> H >> W;
    cin >> N;
    int input1, input2;
    for(int i=0; i<N; i++){
        cin >> input1 >> input2;
        sticker.push_back(make_pair(input1, input2));
    }

    for(int i=0; i<sticker.size() - 1; i++){
        for(int j=i+1; j<sticker.size(); j++){
            put(i, j);
        }
    }

    cout << result;
    return 0;
}