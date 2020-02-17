// 패션왕 신해빈
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int T, test_case, n, result = 1;
string clothes, Type;
vector<pair<string, int> > arr;

int main(void){
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> clothes >> Type;
            bool check = false;

            for(int j=0; j<arr.size(); j++){
                if(arr[j].first == Type){
                    ++arr[j].second;
                    check = true;
                    break;
                }
            }

            if(check == false){
                arr.push_back(make_pair(Type, 1));
            }
        }

        for(int j=0; j<arr.size(); j++){ result *= arr[j].second + 1; }

        cout << result - 1 << "\n";
        arr.clear();
        result = 1;
    }

    return 0;
}
