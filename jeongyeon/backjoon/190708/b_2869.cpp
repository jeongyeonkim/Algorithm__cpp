#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a=0, b=0, v=0, day=0, sample=0;
    cin >> a; cin >> b; cin >> v;
    
    day = (v-a)/(a-b);
    sample = (v-a)%(a-b);
    if(sample == 0){
        day +=1;
    }else{
        day += 2;
    }
        
    cout << day;
    return 0;
}