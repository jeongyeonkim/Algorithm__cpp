// 공
#include <iostream>
#include <vector>
using namespace std;
int M, result;
vector<int> arr[4];

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> M;
    arr[1].push_back(1);
    arr[2].push_back(-1);
    arr[3].push_back(-1);

    for(int i=0; i<M; i++){
        int a = 0, b = 0;
        cin >> a >> b;

        arr[a].swap(arr[b]);
    }

    for(int i=1; i<4; i++){
        if(arr[i].front() == 1){ result = i; }
    }
    cout << result;
    return 0;
}