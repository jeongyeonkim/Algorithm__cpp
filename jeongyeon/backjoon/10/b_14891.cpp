// 톱니바퀴
#include <iostream>
#include <deque>
#include <stack>
using namespace std;
int K;
int direction[2][4] = {{1, -1, 1, -1}, {-1, 1, -1, 1}};
deque<int> wheels[4];
stack<int> rotation;
void clockwise(int idx, int dir){
    if(dir == 1){
        wheels[idx].push_front(wheels[idx].back());
        wheels[idx].pop_back();
    }else{
        wheels[idx].push_back(wheels[idx].front());
        wheels[idx].pop_front();
    }
}

int score(){
    int result = 0;
    for(int i=0; i<4; i++){
        switch (i)
        {
        case 0:
            if(wheels[1].front() == 1){ result += 1; }
            break;
        case 1:
            if(wheels[1].front() == 1){ result += 2; }
            break;
        case 2:
            if(wheels[1].front() == 1){ result += 4; }
            break;
        case 3:
            if(wheels[1].front() == 1){ result += 8; }
            break;
        }
    }
    return result;
}

int main(void){
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            int a; scanf("%1d", &a);
            wheels[i].push_back(a);
        }
    }
    cin >> K;

    while(K--){
        int num=0, dir=0, i=-1;
        bool l = true;

        cin >> num >> dir;
        int z = num-1;
        if(direction[0][z] == dir){ i = 0; }
        else{ i = 1; }

        while (z+1 < 4){
            if(wheels[z][2] != wheels[z+1][6]){ rotation.push(z); }
            z++;
        }

        z = num-1;
        while(z-1 >= 0){
            if(wheels[z][2] != wheels[z-1][6]){ rotation.push(z); }
            z--;
        }

        for(int j=0; i<rotation.size(); j++){
            if(l == true){
                clockwise(rotation.top(), direction[i][j]); 
                if(rotation.top() == num-1){ l = false; }
                rotation.pop();
            }
        }
    }

    cout << score();
}