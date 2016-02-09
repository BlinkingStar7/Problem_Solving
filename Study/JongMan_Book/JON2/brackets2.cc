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
#include <set>
#include <numeric>
#include <stack>
using namespace std;

int testNum;

int main () {
	cin >> testNum;
	char x;

	while (testNum--) {
		stack <char> b;
		string input;
		cin >> input;
		int flag = 1;
		for (int i=0; i<input.size(); ++i) {
			x = input[i];
			if (x == ')' || x == '}' || x == ']') {
				if (b.size() == 0 || (x == ')' && b.top() != '(') || (x == '}' && b.top() != '{') || (x == ']' && b.top() != '[')) {
					flag = 0; break;
				}
				b.pop();
			}
			else b.push(x);
		}
		if (flag == 0 || b.size() != 0) cout << "NO"<<endl;
		else cout << "YES" << endl;
	}


	return 0;
}

