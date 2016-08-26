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

int N, Q, X[100001];
int main () {
	scanf("%d", &N);
	for (int i=0; i<N; ++i)
		scanf("%d", X+i);

	sort(X, X+N);
	scanf("%d", &Q);
	for (int i=0; i<Q; ++i) {
		int t;
		scanf("%d", &t);
		printf("%d\n", upper_bound(X, X+N, t)-X);
	}

	return 0;
}


