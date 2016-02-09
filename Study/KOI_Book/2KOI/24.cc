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

typedef struct Case {int a, b;} C;
int N, M, Memo[18][18];
C Case[18];

int Distance(C x, C y) { return abs(x.a - y.a) + abs(x.b - y.b); } 
int Solve(int x, int y) {
	int next = max(x, y) + 1;
	if (next == M + 2) return 0;

	int &ret = Memo[x][y];
	if (ret != -1) return ret;

	return ret = min (Distance(Case[x], Case[next]) + Solve(next, y), Distance(Case[y], Case[next]) + Solve(x, next));
}

int main () {
	memset(Memo, -1, sizeof(Memo));
	cin >> N >> M;
	Case[0] = (C) {1, 1};
	Case[1] = (C) {N, N};
	for (int i=0; i<M; ++i) {
		int a, b;
		cin >> a >> b;
		Case[i+2] = (C) {a, b};
	}

	cout << Solve (0, 1) << endl;
	return 0;
}

