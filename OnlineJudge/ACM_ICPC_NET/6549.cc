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

int N, H[100002], R[100002], L[100002];

int main () {
	while (scanf("%d", &N) != EOF && N) {
		H[0] = H[N+1] = -1;
		for (int i=1; i<=N; ++i) scanf("%d", H+i);
		for (int i=1; i<=N; ++i) {
			int cand = i-1;
			while(H[cand] >= H[i]) cand = L[cand];
			L[i] = cand;
		}

		for (int i=N; i>=1; --i) {
			int cand = i+1;
			while(H[cand] >= H[i]) cand = R[cand];
			R[i] = cand;
		}

		long long ans = 0;
		for (int i=1; i<=N; ++i)
			ans = max(ans, (long long)(R[i]-L[i]-1)*H[i]);
		printf("%lld\n", ans);
	}
	return 0;
}


