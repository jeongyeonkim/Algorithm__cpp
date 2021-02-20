// 739
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
stack<pair<int, int>> temperatures;

// 48ms 44.9MB
// 1. stack 사용 > 배열 탐색하면 시간 초과 날거 같고, 자기 보다 큰지 작은지만 판별
// 2. 스택 내 top 값이 배열 값보다 작으면 따듯한 온도니까 pop
// 3. 따듯해지는 날짜를 결과 값에 넣기 위해 index값도 stack에 저장 > pair 사용
vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> result;
    temperatures.push(make_pair(T[0], 0));
    result.push_back(0);

    for(int i=1; i<T.size(); i++){
        while(true){
            if(temperatures.empty() || temperatures.top().first >= T[i]){
                temperatures.push(make_pair(T[i], i));
                break;
            }

            result[temperatures.top().second] = i - temperatures.top().second;
            temperatures.pop();
        }
        
        result.push_back(0);
    }

    return result;
}

int main(){
    vector<int> input;
    input.push_back(73);
    input.push_back(74);
    input.push_back(75);
    input.push_back(71);
    input.push_back(69);
    input.push_back(72);
    input.push_back(76);
    input.push_back(73);

    input = dailyTemperatures(input);
    for(int i=0; i<input.size(); i++){ cout << input[i] << " "; }
    return 0;
}