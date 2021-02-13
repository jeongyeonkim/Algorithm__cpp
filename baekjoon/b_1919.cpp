// 애너그램 만들기
#include <iostream>
#include <string>
using namespace std;
int alpabat_1[27], alpabat_2[27];
string str;
int result;

int main() {
	cin >> str;
	for(int i=0; i<str.length(); i++){
		alpabat_1[str[i] - 'a']++;
	}
	cin >> str;
	for(int i=0; i<str.length(); i++){
		if(alpabat_1[str[i] - 'a'] > 0){
			alpabat_1[str[i] - 'a']--;
		}
		else{
			alpabat_2[str[i] - 'a']++;
		}
	}
	
	for(int i=0; i<26; i++){
		result += alpabat_1[i];
		result += alpabat_2[i];
	}
	
	cout << result;
	return 0;
}