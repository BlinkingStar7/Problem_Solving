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
#include <set>
using namespace std;

const int MAXN = 10000000;
int testNum, minFactor[MAXN+1], N, L, H;

void eratos() {
	minFactor[0] = minFactor[1] = -1;
	for (int i=2; i<=MAXN; ++i)
		minFactor[i] = i;

	int sqrtn = int(sqrt(MAXN));

	for (int i=2; i<=sqrtn; ++i) {
		if (minFactor[i] == i) {
			for (int j=i*i; j<=MAXN; j+=i)
				if (minFactor[j] == j)
					minFactor[j] = i;
		}
	}
}

int Solve(int x) {
	int last = -1, num = 0, ret = 1;
	while (x > 1) {
		int cur = minFactor[x];
		if (last == -1 || cur == last)
			++num;
		else {
			ret *= (num+1);
			num = 1;
		}
		last = cur;
		x/=cur;
	}
	ret *= (num+1);

	return ret == N;
}

int main () {
	cin >> testNum;
	eratos();

	while (testNum--) {
		cin >> N >> L >> H;
		int ans = 0;
		for (int i=L; i<=H; ++i)
			if (Solve(i))
				++ ans;
		cout << ans << endl;
	}


	return 0;
}

