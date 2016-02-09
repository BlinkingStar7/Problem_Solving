#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;

string Bracket;

int Solve (string &b) {
	stack<char> s;
	int ret = 0, cur = 1;
	bool flag = false;

	for (int i=0; i<b.size(); ++i) {
		if (b[i] == '(' || b[i] == '[') {
			s.push(b[i]);
			cur *= b[i] == '(' ? 2 : 3;
			flag = true;
		}
		else {
			if (s.empty()) return 0;
			char x = s.top(); s.pop();
			if ((x == '(' && b[i] != ')') || (x == '[' && b[i] != ']')) return 0;

			if (flag) {
				ret += cur;
				flag = false;
			}
			cur /= (x == '(' ? 2 : 3);
		}
	}
	return s.empty() ? ret : 0;
} 




int main () {
	cin >> Bracket;
	cout << Solve(Bracket) << endl;
	return 0;
}

