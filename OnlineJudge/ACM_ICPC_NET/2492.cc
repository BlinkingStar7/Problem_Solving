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
#include <map>
#include <numeric>
using namespace std;

int N, M, T, K, X[101], Y[101];
pair<int, int> pos[101];

int calcNum (int x, int xx, int y, int yy) {
	int ret = 0;
	for (int i=0; i<T; ++i) {
		int a=pos[i].first, b=pos[i].second;
		if (a>=x&&a<=xx && b>=y&&b<=yy)
			++ret;
	}
	return ret;
}

int main () {
	cin >> N >> M >> T >> K;
	for (int i=0; i<T; ++i) {
		scanf("%d %d", X+i, Y+i);
		pos[i].first = X[i];
		pos[i].second = Y[i];
	}
	sort(X, X+T);
	sort(Y, Y+T);

	int m = 0, x, y;

	for (int i=0; i<T; ++i) {
		for (int j=0; j<T; ++j) {
			int cand = calcNum (X[i], X[i]+K, Y[j], Y[j]+K);
			if (cand > m) {
				m = cand;
				x = X[i];
				y = Y[j]+K;
			}
		}
	}
	printf("%d %d\n%d\n", x, y, m);
	
	return 0;
}

