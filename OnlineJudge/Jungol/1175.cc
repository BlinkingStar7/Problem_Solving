#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

void Solve (int n, int m, vector<int> &x) {
	if (n == 0) {
		if (m == 0) {
			for (int i=0; i<x.size(); ++i)
				printf("%d ", x[i]);
			puts("");
		}
		return;
	}

	for (int i=1; i<=6; ++i) {
		x.push_back(i);
		Solve(n-1, m-i, x);
		x.pop_back();
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> x;

	Solve (n, m, x);
	return 0;
}


