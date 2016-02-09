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

int C;

int main () {
	cin >> C;

	while (C--) {
		int N, D[101];
		cin >> N;
		D[1] = 1, D[2] = 2;
		for (int i=3; i<=N; ++i)
			D[i] = (D[i-1] + D[i-2]) % 1000000007;
		cout << D[N] << endl;

	}


	return 0;
}

