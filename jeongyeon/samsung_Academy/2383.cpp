// [모의 SW 역량테스트] 점심 식사시간
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
int test_case, T, result, N;
vector<pair <int, int> > person;
struct info{
    int x, y, h;
};
vector<info> stairs;



int main(int argc, char** argv){
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        result = 1e9;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                int input; cin >> input;
                if(input == 1){ person.push_back(make_pair(i, j)); }
                else if(input > 1){ stairs.push_back({i, j, input}); }
            }
        }


        cout << "#" << test_case << " " << result << "\n"; 
        stairs.clear(); person.clear();
    }
    return 0;
}