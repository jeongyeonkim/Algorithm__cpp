//30
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string input;
int sum, check0;
vector<int> arr;

bool asc(int a, int b){ return a > b; }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> input;

    for(int i=0; i<input.length(); i++){
        arr.push_back(input[i]-'0');
        sum += arr[i];
        if(arr[i] == 0){ check0 = 1; }
    }

    //각 항의 숫자 합이 3의 배수가 아닐경우, 숫자에 0 이없어 30의 배수가 아닐 경우 -1 출력
    if( sum%3 != 0 || check0 == 0 ){
        cout << -1;
        return 0;
    }

    sort(arr.begin(), arr.end(), asc);

    //정렬된 큰 수부터 차례대로 출력.
    //각 항의 숫자 합이 3이기 때문에 어떤 조합을 해도 끝이 0이면 30의 배수가 출력 됨.
    for(int i=0; i<arr.size(); i++){
        cout << arr[i];
    }

}