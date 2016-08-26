#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
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
typedef long long ll;
typedef unsigned long long ull;

const ll INF = 1e15, MAX = 100005;
int N, C[MAX];
ll memo[MAX][2];
string S[MAX];

bool Cmp(int a, int s, int aa, int ss) {
	int m = min(S[a].size(), S[aa].size());

	for (int i=0; i<m; ++i) {
		char c = S[a][s == 0 ? i : S[a].size()-i-1], cc = S[aa][ss == 0 ? i : S[aa].size()-i-1];
		if (c != cc) return c < cc;
	}

	return S[a].size() <= S[aa].size();
}

ll Solve (int cur, int state) {
	if (cur == N-1) return 0;

	ll &ret = memo[cur][state];
	if (ret != -1) return ret;

	ret = INF; 
	if (Cmp(cur, state, cur+1, 0)) ret = Solve(cur+1, 0);
	if (Cmp(cur, state, cur+1, 1)) ret = min (ret, Solve(cur+1, 1) + C[cur+1]);

	return ret;
}

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
		scanf("%d ", C+i);

	for (int i=0; i<N; ++i)
		cin >> S[i];

	memset(memo, -1, sizeof(memo));
	ll ret = min(Solve(0, 0), C[0] + Solve(0, 1));

	printf("%lld\n", ret >= INF ? -1 : ret);

	return 0;
}


