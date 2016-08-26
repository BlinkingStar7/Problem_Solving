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
int N, A[MAX], B[MAX], F[MAX], FW[MAX];
pii P[MAX];

void update (int p, int v) {
	for (; p<=N; p+=p&-p)
		FW[p] += v;
}

int query (int p) {
	int ret = 0;
	for (; p; p-=p&-p)
		ret += FW[p];
	return ret;
}


int main () {
	scanf("%d", &N);
	for (int i=0; i<N; ++i) {
		scanf("%d", A+i);
		P[i] = make_pair(A[i], i);
	}

	sort(P, P+N);
	int cnt = 0, cur = P[0].first, num = 0;
	
	for (int i=0; i<N; ++i) {
		int pos = P[i].second;
		if (P[i].first == cur) {
			A[pos] = cnt;
			B[pos] = ++num;
		}
		else {
			F[cnt++] = num;
			A[pos] = cnt;
			B[pos] = num = 1;
			cur = P[i].first;
		}
	}

	F[cnt++] = num;

	for (int i=0; i<N; ++i)
		update(B[i], 1);

	ll ans = 0;
	for (int i=0; i<N; ++i) {
		update(F[A[i]]--, -1);
		ans += query(B[i]-1);
	}

	cout << ans << endl;
	

	return 0;
}


