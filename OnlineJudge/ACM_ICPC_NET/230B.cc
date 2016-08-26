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

int N;
bool Compo[1000*1001];

int main () {
	scanf("%d", &N);
	for (int i=2; i<=1000; ++i) {
		if (!Compo[i]) {
			for (int j=i*i; j<=1000*1000; j+=i)
				Compo[j] = true;
		}
	}

	for (int i=0; i<N; ++i) {
		ll t, sq;
		scanf("%lld", &t);
		if (t == 1) { printf("NO\n"); continue; }
		sq = sqrt(t);
		printf("%s\n", t == sq*sq && !Compo[sq] ? "YES" : "NO");
	}


	return 0;
}


