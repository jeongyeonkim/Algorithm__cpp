#include <iostream>
#include <queue>
#include <functional>
#include <cmath>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    
    int n=0, k=0;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> input;
    while(n!=0){
        cin >> k;
        if(k != 0)
            input.push(make_pair(abs(k),k));
        else{
            if(input.empty())
                cout << 0 << "\n";
            else{
                cout << input.top().second << "\n";
                input.pop();
            }
        }
        n--;
    }
    return 0;
}