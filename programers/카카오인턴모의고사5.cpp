#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 200000001;
    int len = stones.size()-k;
    
    for(int i=0; i<=len; i++){
        int num = stones[i], numPos = 0;
        for(int j=1; j<k; j++){
            if(num < stones[i+j]){
                num = stones[i+j];
                numPos = j;
            }
        }
        i += numPos;
        if(answer > num){ answer = num; }
    }
    
    return answer;
}