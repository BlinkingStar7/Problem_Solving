#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int tW, N, A, B, D[10001], Memo[10001];

int Solve (int n) {
	if (n>=N) return 0;
	int &ret = Memo[n];
	if (ret != -1) return ret;

	ret = 0;

	return ret = min (A*D[n] + Solve(n+1), B + Solve(n+5));
}


int main() {
	cin >> tW;

	while (tW--) {
		cin >> N >> A >> B;
		for (int i=0; i<N; ++i) 
			scanf("%d", D + i);
		memset(Memo, -1, sizeof(Memo));

		cout << Solve(0) << endl;
	}
	return 0;
}

