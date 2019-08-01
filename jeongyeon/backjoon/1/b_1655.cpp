#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    
    int n=0, k=0;
    cin >> n;
    priority_queue<int> input_max;
    priority_queue<int, vector<int>, greater<int>> input_min;
    
    while(n--){
        cin >> k;
        if(input_max.size() == input_min.size())
            input_max.push(k);
        else 
            input_min.push(k);
        
        if(!input_max.empty() && !input_min.empty() && input_max.top() > input_min.top()){
            int a = input_max.top();
            int b = input_min.top();
            input_max.pop(); 
            input_min.pop();
            input_max.push(b);
            input_min.push(a);
        }
        cout << input_max.top() << "\n";
    }
    return 0;
}