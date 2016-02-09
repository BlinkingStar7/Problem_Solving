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

int testNum, N, pre[101], in[101];

void Solve(int preS, int preE, int inS, int inE) {
	if (preS > preE || inS > inE) return;

	int mid;
	for (mid=inS; mid<=inE; ++mid)
		if (in[mid] == pre[preS]) break;

	Solve (preS+1, preS+mid-inS, inS, mid-1);
	Solve (preS+mid-inS+1, preE, mid+1, inE);
	printf("%d ", pre[preS]);
}


int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;
		for (int i=0; i<N; ++i) cin >> pre[i];
		for (int i=0; i<N; ++i) cin >> in[i];

		Solve (0, N-1, 0, N-1);
	}

	return 0;
}

