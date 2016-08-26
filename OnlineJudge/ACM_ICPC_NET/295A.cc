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

const int MAX = 100005;
int N, M, K, op[MAX][3], A[MAX];
ll arr1[MAX], arr2[MAX];

void update (ll *fw, int p, ll v) {
	for (; p <= MAX; p += p & -p)
		fw[p] += v;
}

ll query (ll *fw, int p) {
	ll ret = 0;
	for (; p; p -= p & -p)
		ret += fw[p];

	return ret;
}

int main () {
	scanf("%d%d%d", &N, &M, &K);
	for (int i=1; i<=N; ++i)
		scanf("%d", A+i);

	for (int i=1; i<=M; ++i)
		scanf("%d%d%d", &op[i][0], &op[i][1], &op[i][2]);

	for (int i=0; i<K; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		update(arr2, a, 1);
		update(arr2, b+1, -1);
	}

	for (int i=1; i<=M; ++i) {
		int t = query(arr2, i);
		update(arr1, op[i][0], (ll)t * op[i][2]);
		update(arr1, op[i][1]+1, (ll)t * -op[i][2]);
	}

	for (int i=1; i<=N; ++i)
		printf("%lld ", A[i] + query(arr1, i));
	puts("");

	return 0;
}


