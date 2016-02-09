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

int C, N, W, V[101], D[101], Memo[1002][102];
string O[101];

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> W;
		for (int i=0; i<N; ++i)
			cin >> O[i] >> V[i] >> D[i];

		memset(Memo, 0, sizeof(Memo));

		for (int n=N-1; n>=0; --n) {
			for (int w=0; w<=W; ++w) {
				if (w >= V[n]) Memo[w][n] = max (Memo[w][n+1], Memo[w-V[n]][n+1] + D[n]);
				else Memo[w][n] = Memo[w][n+1];
			}
		}

		vector<int> l;

		for (int cur = 0, w=W; cur <N; ++cur)
			if (Memo[w][cur] != Memo[w][cur+1]) {
				l.push_back(cur);
				w -= V[cur];
			}

		printf("%d %d\n", Memo[W][0], l.size());
		for (int i=0; i<l.size(); ++i)
			cout << O[l[i]] << endl;

	}


	return 0;
}

