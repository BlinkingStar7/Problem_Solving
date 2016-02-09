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
int Solve(int n) {
	int ans = 0;

	for (int a = 1; a <= n/3; ++a) {
		for (int b = a; a + 2*b <= n; ++b)
			if (2*(a+b) > n) ++ans;
	}
	return ans;
}


int main () {
	cin >> N;

	cout << Solve(N) << endl;

	return 0;
}

