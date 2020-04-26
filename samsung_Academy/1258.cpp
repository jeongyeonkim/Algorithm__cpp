//  [S/W 문제해결 응용] 7일차 - 행렬찾기 
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

// s = 넓이, x = 세로 길이, y = 가로 길이
struct Output{
    int s;
    int x;
    int y;
    Output(const int x, const double y, const char c)
        : s(x), x(y), y(c){}
};

int test_case, T, N;
int arr[101][101];
vector<Output> result;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0}; 

// 넓이 기준 정렬
// 넓이가 같을 경우 세로 길이가 짧은게 먼저
bool compareV(const Output& x, const Output& y){
    if(x.s == y.s){ return x.x < y.x; }
    return x.s < y.s;
}

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){ cin >> arr[i][j]; }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(arr[i][j] != 0){
                    int col = 0, row = 0;
                    // 최대 가로 길이 
                    while(arr[i][j + row]){ row++; }
                    // 최대 세로 길이
                    while (arr[i + col][j]){ col++; }
                    result.push_back(Output(col*row, col, row));

                    // 이미 방문한 인덱스 값 0으로 리셋
                    for(int a=0; a<col; a++){
                        for(int b=0; b<row; b++){ arr[i+a][j+b] = 0; }
                    }
                }
            }
        }

        // 출력
        cout << "#" << test_case << " " << result.size() << " ";
        sort(result.begin(), result.end(), compareV);
        for(int i=0; i<result.size(); i++){ cout << result[i].x << " " << result[i].y << " "; }
        cout << "\n";
        result.clear();
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}
