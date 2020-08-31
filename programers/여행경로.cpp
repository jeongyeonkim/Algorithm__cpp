#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> answer;
int visited[10001]; // 티켓 사용 여부
vector<vector<string>> ticket;
bool flag = false; // 이미 답이 나왔을 경우 더이상 경로 검색을 안해도되기 때문에 for문 탈출을 위해 씀

void vacationRoot(string airport, vector<string> res){
    if(res.size() == ticket.size()){ // 방문 공항 수 = 티켓 갯수 + 1
        res.push_back(airport);
        flag = true;
        answer = res;
        return;
    }

    for(int i=0; i<ticket.size(); i++){
        if(flag){ return; } // 이미 답이 나오면 더이상 탐색할 필요x

        if(!ticket[i][0].compare(airport) && !visited[i]){ // 해당 공항에다 갈 수 있는 티켓이 있으면서, 아직 사용하지 않은 티켓일 경우 dfs 들어가기
            visited[i] = 1;
            res.push_back(airport);
            vacationRoot(ticket[i][1], res);
            res.pop_back(); // 백트래킹
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end()); //알파벳 순서가 앞서는거를 return 해야하기 때문에 sort
    ticket = tickets;

    for(int i=0; i<tickets.size(); i++){
        if(!ticket[i][0].compare("ICN")){ // ICN 부터 시작
            visited[i] = 1;
            vector<string> tmp;
            tmp.push_back("ICN");
            vacationRoot(tickets[i][1], tmp);

            if(flag){ break; }
            visited[i] = 0;
        }
    }

    return answer;
}