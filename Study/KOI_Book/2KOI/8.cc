#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int N;
string s;
string::iterator it;

void Solve(int size) {
	char c = *(it++);
	if (c == '-') {
		Solve(size/2);
		Solve(size/2);
	}
	else {
		string x(size, c);
		cout << x;
	}
}
	
int main () {
	cin >> N;
	cin >> s;
	it = s.begin();
	Solve(N);
	return 0;
}

