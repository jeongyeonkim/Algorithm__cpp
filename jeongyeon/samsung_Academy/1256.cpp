// [S/W 문제해결 응용] 6일차 - K번째 접미어
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int K, test_case, T;
string word;
vector<string> arr;

int main(int argc, char** argv){
    cin >> T;
    for(test_case = 1; test_case <= T; test_case++){
        cin >> K;
        cin >> word;
        for(int i=0; i<word.length(); i++){
            string temp = "";
            for(int j=i; j<word.length(); j++){
                temp += word[j];
            }
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        
        cout << "#" << test_case << " " << arr[K-1] << "\n";
        arr.clear(); K = 0; word = "";
    }
    return 0;
}
