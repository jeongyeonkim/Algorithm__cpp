#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<string>> answer, snapshotsCopy;
bool num[100001];

int findAccount(string str){
    for(int i=0; i<snapshotsCopy.size(); i++){
        if(snapshotsCopy[i][0].compare(str) == 0){ return i; }
    }
    return -1;
}

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
    snapshotsCopy = snapshots;
    sort(transactions.begin(), transactions.end());

    for(int i=0; i<transactions.size(); i++){
        if(!num[stoi(transactions[i][0])]){
            int pos = -1;
            pos = findAccount(transactions[i][2]);
            if(transactions[i][1].compare("SAVE") == 0){
                if(pos == -1){
                    vector<string> temp;
                    temp.push_back(transactions[i][2]);
                    temp.push_back(transactions[i][3]);
                    snapshotsCopy.push_back(temp);
                }else{
                    int k = stoi(snapshotsCopy[pos][1]) + stoi(transactions[i][3]);
                    snapshotsCopy[pos][1] = to_string(k);
                }
            }else{
                int k = stoi(snapshotsCopy[pos][1]) - stoi(transactions[i][3]);
                snapshotsCopy[pos][1] = to_string(k);
            }
            num[stoi(transactions[i][0])] = true;
        }
    }
    
    sort(snapshotsCopy.begin(), snapshotsCopy.end());
    answer = snapshotsCopy;
    return answer;
}