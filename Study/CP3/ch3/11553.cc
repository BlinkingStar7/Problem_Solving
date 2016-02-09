#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, board[9][9];
		scanf("%d", &n);
		for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", &board[i][j]);
		
		vi permu(n);
		for (int i=0; i<n; ++i) permu[i] = i;

		int ans = INF;
		do {
			int cand = 0;
			for (int i=0; i<n; ++i)
				cand += board[i][permu[i]];
			if (cand < ans) ans = cand;
		} while(next_permutation(permu.begin(), permu.end()));

		printf("%d\n", ans);
	}



	return 0;
}


