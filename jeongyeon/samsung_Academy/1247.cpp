// [S/W 문제해결 응용] 3일차 - 최적 경로
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
int test_case, T, companyX, companyY, homeX, homeY, N;
pair<int, int> point[101];
vector<int> arr;
int result = 987654321;

int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        cin >> companyX >> companyY >> homeX >> homeY;
        for(int i=0; i<N; i++){
            cin >> point[i].first >> point[i].second;
            arr.push_back(i);
        }

        do{
            int distance=0;
            int x=0, y=0, a=0, b=0;
            x = companyX; y = companyY;
            for(int i=0; i<N; i++){
                if(result < distance){ break; }
                a = point[arr[i]].first;
                b = point[arr[i]].second;
                distance += (abs(x-a) + abs(y-b));
                x = a; y = b;
            }
            distance += (abs(x-homeX) + abs(y-homeY));

            result = min(result, distance);
        } while (next_permutation(arr.begin(), arr.end()));
        
        cout << "#" << test_case << " " << result << "\n"; 

        memset(point, 0, sizeof(point));
        result = 987654321;
        arr.clear();
    }
    return 0;
}