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

char s[5001];
int n, ans, p[5001];
int main () {
	gets(s);
	n = strlen(s);

	int m = 0;
	for (int i=1; i<n; ++i) {
		while (m > 0 && s[m] != s[i]) m = p[m-1];
		if (s[m] == s[i]) {
			ans = max(ans, p[i] = ++m);
			if (m == n) m = p[m-1];
		}
	}

	printf("%d\n", ans);
	return 0;
}


