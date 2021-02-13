// 괄호의 값
#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;
string str;
stack<string> arr;
char temp;
int result;
string _close[2] = {"(", "["};
int score[2] = {2, 3};

bool checkInt(string str){
	if(str.compare("(") && str.compare(")") && str.compare("[") && str.compare("]")){
		return true;
	}
	return false;
}

void findFriend(int idx){
	int cnt = 0;
	while(true){
		if(arr.empty()){ result = -1; return; }
		string x = arr.top();
		arr.pop();
		if(!_close[idx].compare(x)){
			if(cnt == 0){ cnt = score[idx]; }
			else{ cnt *= score[idx]; }
			arr.push(to_string(cnt));
			return;
		}
		else if(checkInt(x)){
			cnt += stoi(x);
		}
		else{
			result = -1;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> str;
	for(int i=0; i<str.length(); i++){
		temp = str[i];
		if(result == -1){ continue; } 
		if(temp == '(' || temp == '['){
			string t = "";
			t += temp;
			arr.push(t); }
		else if(temp == ')'){ findFriend(0); }
		else if(temp == ']'){ findFriend(1); }
		else{ result = -1; }
	}
	
	if(result == -1){ cout << 0; }
	else{
		result = 0;
		while(!arr.empty()){
			if(checkInt(arr.top())){
				result += stoi(arr.top());
				arr.pop();
			}
			else{
				result = 0;
				break;
			}
		}
		cout << result;
	}
	return 0;
}