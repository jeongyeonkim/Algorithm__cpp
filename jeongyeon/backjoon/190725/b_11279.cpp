#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    
    int n=0, k=0;
    cin >> n;
    priority_queue<int> input;
    while(n!=0){
        cin >> k;
        if(k != 0)
            input.push(k);
        else{
            if(input.empty())
                cout << 0 << "\n";
            else{
                cout << input.top() << "\n";
                input.pop();
            }
        }
        n--;
    }
    return 0;
}