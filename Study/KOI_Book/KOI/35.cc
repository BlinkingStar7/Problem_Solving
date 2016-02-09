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

int M, N, coin[11], MIN = 0x7fffffff;

void greedySolve(int left, int type, int num) {
	if (left == 0)
		if (MIN > num) {MIN = num; return; }
	if (type == -1) return;

	greedySolve (left%coin[type], type-1, num + left/coin[type]);
}

void Solve(int l, int t, int n) {
	if (l == 0)
		if (MIN > n) { MIN = n; return;}
	if (t == -1) return;

	for (int num=0; num<l/coin[t]; ++num)
		greedySolve (l- num * coin[t], t-1, n + num);
}


int main () {
	cin >> M >> N;
	for (int i=0; i<N; ++i)
		cin >> coin[i];

	greedySolve(M, N-1, 0);
	Solve(M, N-1, 0);
	cout << MIN << endl;
	return 0;
}

