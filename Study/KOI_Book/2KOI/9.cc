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

void Solve (int n, int m, string l) {
	if (n == 0) {
		cout << l << endl;
		return;
	}
	for (int cur = n > m ? m : n; cur >= 1; --cur)
		Solve (n-cur, cur, l + to_string(cur) + " ");
}

int main () {
	cin >> N;
	Solve(N, 987654321, "");
	return 0;
}

