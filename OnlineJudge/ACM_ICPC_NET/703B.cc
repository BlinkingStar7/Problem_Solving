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

int N, K, A[100005];
bool C[100005];
ll sum, cap;

int main () {
	scanf("%d%d", &N, &K);
	
	for (int i=1; i<=N; ++i) {
		scanf("%d", A+i);
		sum += A[i];
	}

	for (int i=1; i<=K; ++i) {
		int t;
		scanf("%d", &t);
		C[t] = true;
		cap += A[t];
	}

	A[0] = A[N];
	C[0] = C[N];
	A[N+1] = A[1];
	C[N+1] = C[1];

	ll ans = 0;
	for (int i=1; i<=N; ++i) {
		if (C[i]) ans += (ll)(sum-A[i])*A[i];
		else ans += (ll)(cap + (C[i-1] ? 0 : A[i-1]) + (C[i+1] ? 0 : A[i+1]))*A[i];
	}

	cout << ans/2 << endl;


	return 0;
}


