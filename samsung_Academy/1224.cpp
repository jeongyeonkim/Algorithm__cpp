//[S/W 문제해결 응용] 2일차 - 최대 상금
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int T, result, cnt;
string input;

void maxMoney(int start, int t){
    if(t == cnt){
        result = max(result, stoi(input));
        return;
    }

    for(int i=start; i<input.length(); i++){
        for(int j=i+1; j<input.length(); j++){
            if(input[i] <= input[j]){
                swap(input[i], input[j]);
                maxMoney(i, t+1);
                swap(input[i], input[j]);
            }
        }
    }

}

int main(int argc, char** argv){
	cin>>T;
	for(int test_case = 1; test_case <= T; ++test_case){
        cin >> input >> cnt;
        result = stoi(input);
        maxMoney(0,0);
        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}