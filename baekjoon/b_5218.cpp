// 알파벳 거리
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int T;
string str1, str2;

int main() {
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> str1 >> str2;
		cout << "Distances: ";
		for(int j=0; j<str1.length(); j++){
			if(str2[j] - str1[j] >= 0){ cout << str2[j] - str1[j] << " "; }
			else{ cout << 26 + str2[j] - str1[j] << " "; }
		}
		cout << "\n";
	}
	return 0;
}