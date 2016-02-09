#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;

string str;
int C, P = 0;

string Solve() {
	char c = str[P++];
	if (c == 'x') {
		string s1 = Solve();
		string s2 = Solve();
		string s3 = Solve();
		string s4 = Solve();
		return "x" + s3 + s4 + s1 + s2;
	}
	else if (c == 'w') return "w";
	else return "b";
}


int main () {
	cin >> C;
	while (C--) {
		P = 0;
		cin >> str;
		cout << Solve() << endl;
	}

	return 0;
}

