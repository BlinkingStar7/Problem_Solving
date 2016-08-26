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

#define LSOne(S) (S & (-S)) 

const int MAX = 100*1001;
int N, M, K;
ll FW[MAX], A[MAX], B[MAX];

void update(ll* ft, int k, ll v) {
	for (; k <= N; k += LSOne(k)) ft[k] += v;
}

void range_update(int i, int j, ll v)	{
	update(A, i, v);
	update(A, j + 1, -v);
	update(B, i, v * (i - 1));
	update(B, j + 1, -v * j);
}

ll query(ll* ft, int b)	{
	ll sum = 0;
	for (; b; b -= LSOne(b)) sum += ft[b];
	return sum;
}

ll query (int p) {
	return p * query(A, p) - query(B, p);
}

ll query (int p, int q) {
	return query(q) - query(p-1);
}


int main () {
	int C;
	cin >> C;

	while (C--) {
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));

		scanf("%d%d", &N, &M);

		for (int i=0; i<M; ++i) {
			int a, b, c;
			ll d;
			scanf("%d%d%d", &a, &b, &c);
			if (a == 0) {
				scanf("%lld", &d);
				range_update(b, c, d);
			}
			else {
				printf("%lld\n", query(b, c));
			}
		}
	}

	return 0;
}


