#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string answer_sheet, vector<string> sheets) {
    int answer = -1;
    for(int i=0; i<sheets.size()-1; i++){
        for(int j=i+1; j<sheets.size(); j++){
            int cnt = 0, res = 0, maxCnt = 0;
            for(int k=0; k<answer_sheet.size(); k++){
                if(sheets[i][k] == sheets[j][k] && sheets[i][k] != answer_sheet[k]){
                    cnt++;
                }else{
                    maxCnt = max(maxCnt, cnt);
                    res += cnt;
                    cnt = 0;
                }
            }
            maxCnt = max(maxCnt, cnt);
            res += cnt;
            cout << i << " " << j << " " << res << "\n";
            answer = max(answer, res + maxCnt*maxCnt);
        }
    }
    return answer;
}