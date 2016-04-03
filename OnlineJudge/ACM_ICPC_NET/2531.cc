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

int n, k, c, num[60001], dish[30001];
int main () {
	scanf("%d%*d%d%d", &n,&k,&c);
	int kind = 0, ans = 0;
	for (int i=0; i<n; ++i) {
		scanf("%d", dish+i);
		dish[i+n] = dish[i];
		if (num[dish[i]]++ == 0) ++kind;
		if (i>=k && num[dish[i-k]] == 1) {
			--kind;
			num[dish[i-k]]--;
		}

		ans = max(ans, kind + (num[c] ? 0 : 1));
	}
	for (int i=0; i<k; ++i) {
		if (num[dish[n+i]]++ == 0) ++kind;
		if (num[dish[n+i-k]] == 1) {
			--kind;
			num[dish[n+i-k]]--;
		}

		ans = max(ans, kind + (num[c] ? 0 : 1));
	}
	printf("%d\n", ans);

	return 0;
}


