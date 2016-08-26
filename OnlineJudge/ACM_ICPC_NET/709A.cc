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

int N, B, D, sum, ans;
int main () {
	scanf("%d%d%d", &N, &B, &D);
	int sum = 0;
	for (int i=0; i<N; ++i) {
		int t;
		scanf("%d", &t);
		if (t > B) continue;
		sum += t;
		if (sum > D) { sum = 0; ++ans; }
	}

	printf("%d\n", ans);
	return 0;
}


