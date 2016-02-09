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

int flag = 0;
void Solve (int n) {
	if (n == 0) return;
	if (n%10) {
		flag = 1;
		cout << n%10;
		Solve(n/10);
	}
	else if (flag) {
		cout << n%10;
		Solve(n/10);
	}
}

int main () {
	int n;
	cin >> n;

	Solve(n);
	return 0;
}


