// 계란으로 계란치기
// DFS로 탐색
#include <iostream>
#include <vector>
using namespace std;
int N, input1, input2, result;

struct info{ // egg : 내구도, weight : 무게
	int egg, weight;	
};

void eggBreak(vector<info> arr, int idx, int res){
	if(idx >= arr.size()){ // 오른쪽에 더이상 계란이 없을 경우 return
		if(res > result){ result = res; }
		return;
	}

	int idx_egg = arr[idx].egg;
	int idx_weight = arr[idx].weight;
	int tmp_res = res;
	if(idx_egg <= 0){ // 이미 깨진 계란일 경우
		eggBreak(arr, idx + 1, res);
		return;
	}
	bool flag = true;
	
	for(int i=0; i<arr.size(); i++){
		if(i == idx || arr[i].egg <= 0){ continue; }
		flag = false;
		tmp_res = res;
		arr[idx].egg -= arr[i].weight;
		arr[i].egg -= idx_weight;

		if(arr[idx].egg <= 0){ tmp_res++; }
		if(arr[i].egg <= 0){ tmp_res++; }
		eggBreak(arr, idx + 1, tmp_res);
        // 다른 계란 무게 만큼 뺀거 다시 복귀 ->> 백트래킹
		arr[idx].egg += arr[i].weight;
		arr[i].egg += idx_weight;
	}

	if(flag){ eggBreak(arr, idx + 1, res); } 
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	vector<info> vec;
	for(int i=0; i<N; i++){
		cin >> input1 >> input2;
		vec.push_back({input1, input2});
	}
	
	eggBreak(vec, 0, 0);
	cout << result;
	return 0;
}