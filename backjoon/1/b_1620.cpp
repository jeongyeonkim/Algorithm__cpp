//나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    vector<pair<string,int> > inputN;
    string output[M+1], input[N+1];
    for(int i=0; i<N; i++) {
        int b = i;
        cin >> input[i]; 
        inputN.push_back(make_pair(input[i], b));
    }

    sort(inputN.begin(), inputN.end());

    for(int i=0; i<M; i++){
        string inputM;
        cin >> inputM; 

        if(inputM[0] >= '0' && inputM[0] <= '9'){
            output[i] = input[atoi(inputM.c_str())-1];
        }else{
            int start = 0, end = N-1;
            while(start <= end){
                int mid = (start + end)/2;
                if(inputM == inputN[mid].first){
                    output[i] = to_string((inputN[mid].second + 1));
                    break;
                }else if(inputM > inputN[mid].first){
                    start = mid+1;
                }else{
                    end = mid-1;
                }
            } 
        }
    }

    for(int i=0; i<M; i++){
        cout << output[i] << "\n";
    }
}
