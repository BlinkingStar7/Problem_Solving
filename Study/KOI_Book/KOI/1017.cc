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

int N, Position[21], Spring[21][2], Visited[21];

int Solve2 (int cur) {
	if (cur == 0) return 1;

	int ret = 0;

	for (int next = cur - 1; next >= 0; --next)
		if (!Visited[next] && Spring[next][1] && (Position[cur] - Position[next] <= Spring[cur][0])) {
			Visited[next] = 1;
			ret += Solve2 (next);
			Visited[next] = 0;
		}

	return ret;
}

int Solve (int cur) {
	if (cur == N-1) return Solve2 (cur);

	int ret = 0;

	for (int next = cur + 1; next < N; ++next)
		if (!Visited[next] && (Position[next] - Position[cur] <= Spring[cur][0])) {
			Visited[next] = 1;
			ret += Solve (next);
			Visited[next] = 0;
		}

	return ret;
}


int main () {
	cin >> N;
	
	for (int i=0; i<N; ++i)
		scanf("%d %d %d", Position + i, &Spring[i][0], &Spring[i][1]);

	cout << Solve (0) << endl;

	return 0;
}

