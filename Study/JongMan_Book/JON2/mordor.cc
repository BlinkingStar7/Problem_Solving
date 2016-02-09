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

const int MAX = 987654321, MIN =-987654321;
int testNum, N, Q, minTree[1<<18], maxTree[1<<18];

int FindMax (int a, int b) {
	int ret = MIN;
	while (a < b) {
		if (a%2==1) ret = max(ret, maxTree[a++]);
		if (b%2==0) ret = max(ret, maxTree[b--]);
		a>>=1, b>>=1;
	}
	if (a == b) ret = max(ret, maxTree[a]);
	return ret;
}

int FindMin (int a, int b) {
	int ret = MAX;
	while (a < b) {
		if (a%2==1) ret = min(ret, minTree[a++]);
		if (b%2==0) ret = min(ret, minTree[b--]);
		a>>=1, b>>=1;
	}
	if (a == b) ret = min(ret, minTree[a]);
	return ret;
}
	
int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> Q;
		int base;
		for (base = 1; base<N; base*=2);
		for (int i=0; i<2*base; ++i) {
			minTree[i] = MAX;
			maxTree[i] = MIN;
		}

		for (int i=0; i<N; ++i) {
			int num;
			scanf("%d", &num);
			minTree[base+i] = maxTree[base+i] = num;
		}


		for (int i=base-1; i>=1; --i) {
			minTree[i] = min(minTree[i*2], minTree[i*2+1]);
			maxTree[i] = max(maxTree[i*2], maxTree[i*2+1]);
		}

		for (int i=0; i<Q; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);

			printf("%d\n", FindMax(base + a, base + b) - FindMin(base + a, base + b));
		}
	}


	return 0;
}

