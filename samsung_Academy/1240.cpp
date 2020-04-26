//  [S/W 문제해결 응용] 1일차 - 단순 2진 암호코드
#include <iostream>
#include <string>
using namespace std;
int t_case, n, m, even, odd, val;

int main() {
	string code, tmp, cipher[10] = { "0001101","0011001","0010011","0111101","0100011",
					"0110001","0101111","0111011","0110111","0001011" };
	cin >> t_case;

	for (int i = 1; i <= t_case; i++) {
		val = 0;
		odd = 0;
		even = 0;
		cin >> n >> m;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp.find('1') != -1) code = tmp;
		}
		code.assign(code, code.rfind('1') - 55, 56);

		for (int j = 1; j <= 8; j++) {
			tmp.assign(code, (j - 1) * 7, 7);
			for (int k = 0; k < 10; k++) {
				if (tmp.compare(cipher[k]) == 0) {
					if (j % 2 != 0) odd += k;
					else even += k;
					val += k;
					break;
				}
			}
		}

		if (((odd * 3) + even) % 10 == 0) cout << "#" << i << " " << val << "\n";
		else cout << "#" << i << " 0\n";
	}
	return 0;
}
