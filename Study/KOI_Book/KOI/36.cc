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

typedef struct Point {int y, x; } P;
int N, MIN = 0x7fffffff,  W;
P I[17];

int Dis (P a, P b) { return abs(a.y - b.y) + abs(a.x - b.x); }

void Greedy (int a, int b, int sum) {
	int next = max(a, b) + 1;
	if (next == W+2) {MIN = sum; return;}

	if (Dis (I[a], I[next]) < Dis (I[b], I[next])) return Greedy(next, b, sum + Dis (I[a], I[next]));
	else return Greedy(a, next, sum + Dis (I[b], I[next]));
}

void Solve (int a, int b, int sum) {
	int next = max(a, b) +1;
	if (next == W+2) {
		if (MIN > sum) MIN = sum;
		return;
	}

	Greedy(next, b, sum + Dis (I[a], I[next]));
	Greedy(a, next, sum + Dis (I[b], I[next]));
}

int main () {
	cin >> N >> W;
	I[0] = (P) {1, 1};
	I[1] = (P) {N, N};

	for (int i=0; i<W; ++i) {
		int x, y;
		cin >> x >> y;
		I[i+2] = (P) {x, y};
	}

	Greedy(0, 1, 0);
	Solve (0, 1, 0 );
	cout << MIN << endl;
	return 0;
}

