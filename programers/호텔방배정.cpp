#include <map>
#include <string>
#include <vector>
using namespace std;
map<long long, long long> room;

long long find(long long n){
    if(room.find(n) == room.end()){ return  n; }
    return room[n] = find(room[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    long long num;
    room.insert(make_pair(0, 0));
    for(int i=0; i<room_number.size(); i++){

        num = room_number[i];
        if(room.find(num) != room.end()){ num = find(room[num]); }
        room[num] = num + 1;
        answer.push_back(num);
    }
    return answer;
}