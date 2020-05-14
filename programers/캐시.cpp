#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0){ return cities.size() * 5; }
    int answer = 0;
    vector<string> arr;

    for(int i=0; i<cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        int j = 0;
        for(j=0; j<arr.size(); j++){
            if(cities[i] == arr[j]){
                arr.erase(arr.begin() + j);
                arr.push_back(cities[i]);
                answer++;
                break;
            }
        }

        if(j == arr.size()){
            answer += 5;
            if(arr.size() >= cacheSize){ arr.erase(arr.begin()); }
            arr.push_back(cities[i]);
        }
    }
    return answer;
}