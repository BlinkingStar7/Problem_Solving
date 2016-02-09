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
#include <numeric>
using namespace std;

int testNum, N, Q, parent[100001], depth[100001];

int CalcDepth(int n) {
	int &ret = depth[n];
	if (ret != -1) return ret;

	if (n == 0) return ret = 0;
	return 1 + CalcDepth(parent[n]);
}

int main () {
	cin >> testNum;

	while (testNum--) {
		memset(depth, -1, sizeof(depth));
		cin >> N >> Q;
		for (int i=1; i<N; ++i)
			scanf("%d", parent+i);

		for (int i=0; i<N; ++i)
			CalcDepth(i);

		int base=1;
		for (;base<2*N-3;base*=2);

		int prev;
		for (int i=0; i<2*N-3; ++i) {




	}


	return 0;
}

