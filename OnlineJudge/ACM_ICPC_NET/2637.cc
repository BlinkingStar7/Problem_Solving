#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int N, M, Need[101][101];
bool Comp[101];
int Ans[101];
void Solve (int comp, int num) {
	if (!Comp[comp]) {
		Ans[comp] += num;
		return;
	}
	for (int i=1; i<=N; ++i)
		if (Need[comp][i])
			Solve(i, num*Need[comp][i]);
}
int main() {
	cin >> N >> M;

	for (int i=0; i<M; ++i) {
		int x, a, b;
		scanf("%d %d %d", &x, &a, &b);
		Need[x][a] += b;
		Comp[x] = true;
	}

	Solve (N, 1);

	for (int i=1; i<=N; ++i)
		if (Ans[i])
			printf("%d %d\n", i, Ans[i]);


	return 0;
}


