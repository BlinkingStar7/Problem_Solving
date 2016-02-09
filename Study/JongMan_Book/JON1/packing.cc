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
using namespace std;

int C, N, W, V[101], D[101], Memo[1001][101];
string O[101];

int Solve (int vol, int n) {
	if (n == N) return 0;

	int &ret = Memo[vol][n];
	if (ret != -1) return ret;

	ret = 0;
	
	for (int next = n; next <N; ++next)
		if (V[next] <= vol)
			ret = max (ret, D[next] + Solve (vol - V[next], next + 1));

	return ret;
}

void Reconstruct (vector<int> &list) {
	int w = W, cur = 0;
	for (int cur = 0; cur < N; ++cur) {
		if (Solve(w, cur) != Solve (w, cur+1)) {
				list.push_back(cur);
				w -= V[cur];
			}
	}
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> W;
		for (int i=0; i<N; ++i)
			cin >> O[i] >> V[i] >> D[i];

		memset(Memo, -1, sizeof(Memo));

		cout << Solve (W, 0);

		vector<int> l;
		Reconstruct (l);

		cout << " " << l.size() << endl;
		for (int i=0; i<l.size(); ++i)
			cout << O[l[i]] << endl;

	}


	return 0;
}

