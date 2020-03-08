// 일곱 난쟁이
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> dwarf, result;
int sum;

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i=0; i<9; i++){
        int a = 0; cin >> a;
        dwarf.push_back(a);
    }

    sort(dwarf.begin(), dwarf.end());
    do{
        sum = 0;
        for(int i = 0; i < 7; i++){ sum += dwarf[i]; result.push_back(dwarf[i]); }
        if(sum == 100){
            for(int i=0; i<result.size(); i++){ cout << result[i] << "\n";}
            break;
        }else{ result.clear(); }
    }while(next_permutation(dwarf.begin(), dwarf.end()));
    
    return 0;
}