#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int num=0;
    cin >> num;
    
    while(num--){
        int n=0, m=0, result=1;
        cin >> n >> m;
        priority_queue<int> arr_p;
        queue<pair<int, int>> arr;
        for(int i=0; i<n; i++){
            int k=0; cin >> k;
            if(i == m)
                arr.push(make_pair(k,m));
            else
                arr.push(make_pair(k,-1));
            arr_p.push(k);
        }
        while(1){
            if(arr.front().second == m && arr_p.top() == arr.front().first){
                cout << result<< "\n";
                break;
            }
            else{
                if(arr_p.top() == arr.front().first){
                    result++;
                    arr_p.pop(); arr.pop();
                }else{
                    arr.push(arr.front());
                    arr.pop();
                }
            }
        }
    }
    return 0;
}