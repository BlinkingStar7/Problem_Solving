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

int n, ans[31];

int main () {
	scanf("%d", &n);
	int cur = 0;
	for (int i=0; i<n; ++i) {
		while (ans[cur])
			cur = (cur+1)%n;
		int t; scanf("%d", &t);
		ans[cur] = t;
		cur = (cur+t)%n;
	}
	printf("%d\n", n);
	for (int i=0; i<n; ++i)
		printf("%d ", ans[i]);

	return 0;
}


