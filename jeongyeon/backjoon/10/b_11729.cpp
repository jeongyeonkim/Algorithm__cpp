#include <iostream>
    #include <vector>
    using namespace std;
    vector<pair<int, int>> answer;
    void move(int count, int start, int temp, int goal) {
    	if(count == 1) {
            answer.push_back(make_pair(start, goal));
            return;
        }
        move(count-1, start, goal, temp); // start->temp
        answer.push_back(make_pair(start, goal));
        move(count-1, temp, start, goal); // temp->goal
    }
    
    int main() {
       int n;
       cin >> n;
       move(n, 1, 2, 3);
       cout << answer.size() << "\n";
       for(auto v : answer) {
           cout << v.first << " " << v.second << "\n";
       }
       return 0;
    }