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

const int MAX = 1000001;
int N, A[MAX], fq[MAX], R[MAX], cnt[MAX], FW[MAX], sz;

void update (int p, int v) {
	for (; p<=N; p += p & -p)
		FW[p] += v;
}

int query (int p) {
	int ret = 0;
	for (; p; p -= p & -p)
		ret += FW[p];
	return ret;
}

int main () {
	scanf("%d", &N);
	for (int i=0; i<N; ++i) {
		scanf("%d", A+i);
		fq[i] = A[i];
	}

	sort(fq, fq+N);
	int sz = unique(fq, fq+N) - fq;

	for (int i=0; i<N; ++i)
		A[i] = lower_bound(fq, fq+sz, A[i]) - fq;

	for (int i=N-1; i>=0; --i) {
		R[i] = ++cnt[A[i]];
		update (R[i], 1);
	}

	memset(cnt, 0, sizeof(cnt));

	ll ans = 0;
	for (int i=0; i<N; ++i) {
		++cnt[A[i]];
		update (R[i], -1);
		ans += query(cnt[A[i]]-1);
	}

	cout << ans << endl;
	return 0;
}


