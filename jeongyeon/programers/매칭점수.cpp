#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
map<string, pair <int, vector<string> > > score;
vector<string> arr;
int maxPos, maxScore;

int solution(string word, vector<string> pages) {
    int answer = 0;
    for(int i=0; i<pages.size(); i++){
        for(int w=0; w<pages[i].size(); w++){ // 대문자 소문자 변환
            if(pages[i][w] >= 'A' && pages[i][w] <= 'W'){ pages[i][w] = pages[i][w] + 'a' - 'A'; }
        }

        int posHead = pages[i].find("<head>");
        string metaStr = pages[i].substr(posHead, pages[i].find("</head>") - posHead);
        int posHttp = metaStr.find("https://");
        string id = metaStr.substr(posHttp + 8, metaStr.find("/>") - (posHttp + 8));
        arr.push_back(id);

        int posBody = pages[i].find("<body>") + 6;
        string bodyStr = pages[i].substr(posBody, pages[i].find("</body>") - posBody);
        bool urlCheck = false;
        for(int j=posBody; j<posBody + bodyStr.length(); j++){
            if(pages[i][j] == '<'){ urlCheck = true; }
            else if(pages[i][j] == '>'){ urlCheck = false; }

            if(!urlCheck){ // 단어 개수 세기
                int idx = j;
                while (pages[i].find(word, idx) != string::npos){
                    if(idx >= posBody + bodyStr.length()){ break; }
                    idx = pages[i].find(word, idx);
                    bool check = true;
                    if(idx > 0 && pages[i][idx-1] >= 'a' && pages[i][idx-1] <= 'z'){ check = false; }
                    if(idx < pages[i].size()-1 && pages[i][idx+word.length()+1] >= 'a' && pages[i][idx+word.length()+1] <= 'z'){ check = false; }

                    if(check){
                        score[id].first++;
                        idx += word.length();
                    }
                }
                
            }else{ // 외부 링크 개수 세기
                int idx = j;
                while (bodyStr.find("https://", idx) != string::npos) {
                    idx =  bodyStr.find("https://", idx);

                    if(idx >= bodyStr.length()){ break; }
                    string otherURL;
                    for(int k=idx; k!='"'; k++){ otherURL += bodyStr[k]; }
                    score[id].second.push_back(otherURL);
                    idx += 8;
                }
            }
        }
    }

    for(int i=0; i<arr.size(); i++){
        float sum = score[arr[i]].first;
        for(int j=0; j<score[arr[i]].second.size(); j++){ // 링크 점수
            sum += score[score[arr[i]].second[j]].first / score[arr[i]].second.size();
        }
        cout << sum << "\n";
        if(maxScore < sum){
            maxScore = sum;
            maxPos = i;
        }
    }
    answer = maxPos;
    return answer;
}