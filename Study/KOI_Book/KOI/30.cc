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

int P[100001], N;

int Solve(int n) {
	P[0] = 2;
	int i = 1;
	for (int cand = 3; i <= N; cand += 2) {
		bool flag = true;
		for (int j=0; j < i && P[j]*P[j] <= cand; ++j)
			if (cand % P[j] == 0) {
				flag = false;
				break;
			}
		if (flag) P[i++] = cand;
	}
	return P[n-1];
}


int main () {
	cin >> N;
	cout << Solve(N) << endl;

	return 0;
}

