#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<string, double> score, linkID; // 단어 갯수 저장, url 인덱스 값 저장
vector<string> arr, link[21]; // url값 순서대로 저장, 외부 링크 저장

int maxPos, maxScore;

int solution(string word, vector<string> pages) {
    int answer = 0;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    for(int i=0; i<pages.size(); i++){
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower); // 대문자 -> 소문자 변환
        string p = pages[i];

        int posHead = p.find("<meta property=");
        posHead = p.find("og:url", posHead);
        posHead = p.find("http", posHead);
        int posHttpE = p.find('"', posHead);
        string id = p.substr(posHead, posHttpE - posHead);
        arr.push_back(id); // 본인 주소
        linkID.insert(make_pair(id, i));
        
        int posBody = p.find("<body>");
        string bodyStr = p.substr(posBody, p.find("</body>") - posBody);

        int idx = 0;
        while (true){ // 단어 개수 세기
            idx = bodyStr.find(word, idx);
            if(idx < 0){ break; }
            if((bodyStr[idx - 1] >= 'a' && bodyStr[idx - 1] <= 'z') || (bodyStr[idx + word.length()] >= 'a' && bodyStr[idx + word.length()] <= 'z')){}
            else{
                score[id]++;
            }
            idx++;
        }

        idx = 0;
        while (true){
            idx = bodyStr.find("<a href=\"", idx);
            if(idx < 0){ break; }
            idx += 9;
            int urlE = bodyStr.find('"', idx);
            string anotherURL = bodyStr.substr(idx, urlE-idx);
            link[i].push_back(anotherURL);
            idx += anotherURL.length();
        }
    }

    double sum[arr.size()+1];
    memset(sum, 0, sizeof(sum));
    
    for(int i=0; i<arr.size(); i++){
        sum[i] += score[arr[i]];
        for(int j=0; j<link[i].size(); j++){
            if(linkID.find(link[i][j]) != linkID.end()){
                int url_id = linkID[link[i][j]];
                if(link[i].size() == 0){ break; }
                sum[url_id] += (double)score[arr[i]] / (double)link[i].size();
            }
        }
    }
    for(int i=0; i<arr.size(); i++){
        if(maxScore < sum[i]){
            maxScore = sum[i];
            maxPos = i;
        }
    }
    answer = maxPos;
    return answer;
}