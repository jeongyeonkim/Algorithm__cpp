// 하노이 탑 이동 순서.
#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<int, int> > output;

void hanoi(int cnt, int start, int temp, int end){
    if(cnt == 1){
        output.push_back(make_pair(start, end));
        return;
    }

    hanoi(cnt-1, start, end, temp);
    output.push_back(make_pair(start, end));
    hanoi(cnt-1, temp, start, end);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    hanoi(n, 1, 2, 3);

    cout << output.size() << "\n";
    for(int i=0; i<output.size(); i++){
        cout << output[i].first << " " << output[i].second << "\n";
    }
}