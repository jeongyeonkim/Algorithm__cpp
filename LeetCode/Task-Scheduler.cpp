#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int taskArray[26];
int result;
priority_queue<int> taskPQ;

//-------------------------------------------------------------------------------------------

// 56ms 34.4 MB
// 1. 가장 많이 나오는 알파벳이 순환 개수 결정
// ex ) Example 3:
// A B C
// A D E
// A F G    
// A . .
// A . .      >>   (N + 1) * (가장 많이 나오는 알파벳 횟수 - 1)
// A          >>   + 가장 많이 나오는 알파벳 갯수
int leastInterval_2(vector<char>& tasks, int n) {
    int maxTask = 0;
    for(int i=0; i<tasks.size(); i++){
        taskArray[tasks[i] - 'A']++;
        maxTask = max(maxTask, taskArray[tasks[i] - 'A']);
    }

    int maxTaskCount = 0;
    for(int i=0; i<26; i++){
        if(taskArray[i] == maxTask) { maxTaskCount++; }
    }

    return max((int)tasks.size(), (n + 1) * (maxTask - 1) + maxTaskCount);
}


//--------------------------------------------------------------------------------------------

// 120 ms 47.2 MB
// 1. 우선순위 큐 사용
// 2. n 최소 시간 단위 만큼 큐에 있는 알파벳 가져옴
// 3. temp 큐에 사용한 남은 알파벳 push
// 4. 큐에 더이상 남은 알파벳이 없을 경우 남은 n 만큼 더함 
void runCPU(int n){
    priority_queue<int> temp_taskPQ, copy_taskPQ;
    copy_taskPQ = taskPQ;
    int remainderN = n + 1;

    while (remainderN > 0 && !copy_taskPQ.empty()) {
        if(copy_taskPQ.top() - 1 > 0){
            temp_taskPQ.push(copy_taskPQ.top() - 1);
        }
        copy_taskPQ.pop();

        result++;
        remainderN--;
    }

    if(copy_taskPQ.empty() && !temp_taskPQ.empty()){
        result += remainderN;
    }else{
        while (!copy_taskPQ.empty()) {
            temp_taskPQ.push(copy_taskPQ.top());
            copy_taskPQ.pop();
        }
    }

    taskPQ = temp_taskPQ;
    return;
}

int leastInterval_1(vector<char>& tasks, int n) {
    for(int i=0; i< tasks.size(); i++) {
       taskArray[tasks[i] - 'A']++;
    }
    
    for(int i=0; i<26; i++) {
        if(taskArray[i]){
            taskPQ.push(taskArray[i]);
        }
    }

    while (!taskPQ.empty()) {
        runCPU(n);
    }
    
    return result;
}
