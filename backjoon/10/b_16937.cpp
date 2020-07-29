// 두 스티커
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int H, W, N, result;
vector<pair <int, int> > sticker;

void put(int i, int j){

}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> H >> W;
    cin >> N;
    int input1, input2;
    for(int i=0; i<N; i++){
        cin >> input1 >> input2;
        if(input1 > H || input1 > W || input2 > H || input2 > W ){ continue; }
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