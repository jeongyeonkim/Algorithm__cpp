// 두 스티커
/*
1. 두 개의 스티커 고르기 -> 이중 for문으로 선택 (중복 x)
2. 각각의 x, y 길이 비교
    case 1 : - -
    case 2 : | |
    case 3 : - |
    case 4 : -
             |
    위의 4가지 케이스 * 2 -> 90도 회전할 경우  >>> 90도 회전은 H, W 스와프로 처리
*/
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
    
    if(flag){ // 가능한게 있을 경우 result 최대 값으로 갱신
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

    for(int i=0; i<sticker.size() - 1; i++){ // 중복x 조합
        for(int j=i+1; j<sticker.size(); j++){
            put(i, j);
        }
    }

    cout << result;
    return 0;
}