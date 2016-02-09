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

int W, H, N, Shop[101];

int main () {
	cin >> W >> H >> N;
	for (int i=0; i<=N; ++i) {
		int p, d;
		scanf("%d %d", &p, &d);
		if (p == 1) Shop[i] = d;
		if (p == 2) Shop[i] = 2*W + H - d;
		if (p == 3) Shop[i] = 2*(W + H)-d;
		if (p == 4) Shop[i] = W + d;
	}

	int s =0;
	for (int i=0; i<N; ++i) 
		s += min (abs(Shop[i] - Shop[N]), 2*(H+W) - abs(Shop[i] - Shop[N]));

	cout << s << endl;

	return 0;
}

