// [모의 SW 역량테스트] 등산로 조성
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int test_case, T, N, K, result, arr;
int dxy[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int> > land;
vector<vector<bool> > check;
vector<pair<int, int>> max_pos;

void dfs(int x, int y, int k, int height, int length){ // 높이-k는 한 곳만 가능하니까 dfs에서 계속 들고 다님
    check[x][y] = true;
    result = max(result, length);

    for(int i=0; i<4; i++){
        int nx = x + dxy[i][0];
        int ny = y + dxy[i][1];

        if(nx < N && nx > -1 && ny < N && ny > -1){
            if(!check[nx][ny]){ // 아직 방문 안했을 때
                int nh = land[nx][ny];
                if(nh < height){ dfs(nx, ny, k, nh, length + 1); } // 높이 비교
                else{
                    for(int j=k; j>0; j--){ // 높이 - k 비교
                        if(nh-j < height){ dfs(nx, ny, 0, nh-j, length + 1); }
                    }
                    // 높이 - 1이 k 안에 있으면 for 문 안돌려도 됨
                }
            }
        }
    }

    check[x][y] = false;
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N >> K;
        result = 1;
        land.resize(N); check.resize(N);
        int max_input = 0;
        for(int j=0; j<N; j++){
            check[j].resize(N);
            for(int k=0; k<N; k++){
                cin >> arr;
                land[j].push_back(arr);
                if(max_input < arr){ // 최대 높이 정보 max_pos에 담음
                    max_input = arr;
                    if(max_pos.empty()){ max_pos.push_back(make_pair(j, k)); }
                    else{
                        max_pos.clear();
                        max_pos.push_back(make_pair(j, k));
                    }
                }else if(max_input == arr){ max_pos.push_back(make_pair(j, k)); }
            }
        }

        for(int j=0; j<max_pos.size(); j++){
            dfs(max_pos[j].first, max_pos[j].second, K, max_input, 1);
        }

        cout << "#" << test_case << " " << result << "\n"; 
        land.clear(); check.clear(); max_pos.clear();
    }
    return 0;
}
