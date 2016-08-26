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
typedef long long ll;
typedef unsigned long long ull;

int N, A[200005], V[200005], root = -1, ans, cnt;

void dfs (int cur, int color) {
	if (V[cur]) {
		if (V[cur] == color) {
			A[cur] = -1;
			if (root == -1) root = cur;
			++ans;
		}
		return;
	}

	V[cur] = color;
	return dfs (A[cur], color);
}

int main () {
	scanf("%d", &N);
	for (int i=1; i<=N; ++i) {
		scanf("%d", A+i);
		if (A[i] == i) { root = i; }
	}

	if (root != -1) --ans;

	for (int i=1; i<=N; ++i) {
		if (V[i] == 0)
			dfs(i, ++cnt);
	}

	printf("%d\n", ans);
	for (int i=1; i<=N; ++i)
		printf("%d%c", A[i] == -1 ? root : A[i], i == N ? '\n' : ' ');

	return 0;
}


