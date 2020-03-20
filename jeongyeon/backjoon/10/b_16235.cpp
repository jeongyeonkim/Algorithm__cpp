// 나무 재테크
#include <iostream>
#include <deque>
using namespace std;
int N, M, K, x, y, z, result;
int A[11][11], arr[11][11]; // arr == 땅에 있는 양분, A == S2D2가 뿌리는 양분
int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};
deque<int> tree[11][11];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> A[i][j];
            arr[i][j] = 5;
        }
    }
    for(int i=0; i<M; i++){
        cin >> x >> y >> z;
        tree[x-1][y-1].push_back(z);
    }
    result = M;

    while (K--){
        // 봄, 여름
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(tree[i][j].empty()){ continue; }

                // 항상 나이가 많은 나무 부터 죽음 -> 나이가 적은 나무가 먼저 양분을 먹기 때문에
                int sum = 0, deadTree = 0; // sum == 양분으로 변할 죽는 나무 나이/2의 합, deadTree = 죽는 나무의 수
                for(int k=0; k<tree[i][j].size(); k++){
                    if(arr[i][j] < tree[i][j][k]){
                        sum += tree[i][j][k]/2;
                        deadTree++;
                    }else{
                        arr[i][j] -= tree[i][j][k];
                        tree[i][j][k]++;
                    }
                }
                for(int k=0; k<deadTree; k++){ tree[i][j].pop_back(); }
                arr[i][j] += sum;
                result -= deadTree;
            }
        }

        // 가을, 겨울
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(!tree[i][j].empty()){ // 나무가 있을 경우
                    for(int k=0; k<tree[i][j].size(); k++){
                        if((tree[i][j][k])%5 == 0){ // 나무의 나이가 5배수일 경우
                            for(int r=0; r<8; r++){ // 새로운 나무 심기
                                int ni = i + dx[r];
                                int nj = j + dy[r];

                                if(ni < 0 || nj < 0 || ni >= N || nj >= N){ continue; }
                                tree[ni][nj].push_front(1); // 나이가 1인 나무 추가 -> 나이가 1보다 작은 나무는 없음으로 덱 앞에 추가
                                result++;
                            }
                        }
                    }
                }
                arr[i][j] += A[i][j]; // 겨울
            }
        }
    }

    cout << result;
    return 0;
}