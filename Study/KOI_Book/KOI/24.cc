#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int N, chk;
string str;

void Solve (int n) {
	if (chk) return;
	if (n == N) {
		cout << str << endl;
		chk = 1;
		return;
	}

	for (int x = 1; x <= 3; ++x) {
		bool flag = true;
		str += ('0' + x);
		for (int len = 1; len <= (n+1)/2; ++len)
			if (str.substr(n-len+1, len).compare(str.substr(n-2*len+1, len)) == 0) {
				flag = false;
				break;
			}
		if (flag)  Solve (n+1);
		str = str.substr(0, str.size() - 1);
	}
}

int main() {
	cin >> N;
	Solve(0);
	return 0;
}

