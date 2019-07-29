#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> input;

long long histogram(int left, int right){
    if(left == right)
        return input[left];
    long long result = max(histogram(left, (left+right)/2), histogram(((left+right)/2+1), right));
    long long low = (left+right)/2, high = ((left+right)/2 +1);
    long long height = min(input[low], input[high]);
    result = max(result, height*2);
    
    while(left < low || high <right){
        if(high < right && (low == left || input[low-1] < input[high +1])){
            high++; 
            height = min(height, input[high]);
        }else{
            low--;
            height = min(height, input[low]);
        }
        result = max(result, height*(high-low+1));
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
    int n=0, k=0;
    while(cin >> n){
        input.clear();
        if(n == 0)
            break;
        for(int i=0; i<n; i++){
            cin >> k;
            input.push_back(k);
        }
        cout << histogram(0, n-1) << "\n";
    }
    return 0;
}