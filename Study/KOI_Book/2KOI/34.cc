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

typedef struct S {int y, x;} S;
int N, K;
S P[1002]; bool chk[1002];

double Dist (S a, S b) {
	return sqrt((a.y-b.y)*(a.y-b.y) + (a.x-b.x)*(a.x-b.x));
}

bool Solve(int f, int c, int k) {
	if (k == 0 || c == N+1) return Dist(P[c], P[N+1]) <= f*10;

	int ret = false;
	for (int i=1; i<=N+1; ++i)
		if (!chk[i] && Dist (P[c], P[i]) <= f*10) {
			chk[i] = true;
			ret = ret || Solve(f, i, k-1);
			chk[i] = false;
		}
	return ret;	
}

int main () {
	cin >> N >> K;
	for (int i=1; i<=N; ++i) {
		int x, y;
		cin >> x >> y;
		P[i] = (S) {y, x};
	}

	P[0] = (S) {0, 0}, P[N+1] = (S) {10000, 10000};

	int lo = 1, hi = 1415;
	
	while (lo <= hi) {
		memset(chk, false, sizeof(chk));
		chk[0] = true;
		int mid = (lo+hi)/2;
		if (Solve(mid, 0, K)) hi = mid-1;
		else lo = mid+1;
	}

	cout << lo << endl;

	return 0;
}

