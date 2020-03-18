#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++){
        vector<int> arr;
        
        arr.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(arr.begin(), arr.end());
        
        answer.push_back(arr[commands[i][2] - 1]);
    }

    return answer;
}