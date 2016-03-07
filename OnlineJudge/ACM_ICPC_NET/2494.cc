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

int main () {
	int n, f[10001], t[10001];
	scanf("%d", &n);
	for (int i=0; i<n; ++i) scanf("%1d", f+i);
	for (int i=0; i<n; ++i) scanf("%1d", t+i);

	int d[10001][10] = {0}, ans[10001][10];

	for (int i=n-1; i>=0; --i) for (int s=0; s<=9; ++s) {
		int left = (t[i] - f[i] - s + 20) % 10;
		int a = left + d[i+1][(s+left)%10], b = 10 - left + d[i+1][s];
		if (a < b) { d[i][s] = a; ans[i][s] = left;}
		else { d[i][s] = b; ans[i][s] = -(10-left); }
	}

	int s = 0;
	printf("%d\n", d[0][0]);
	for (int i=0; i<n; ++i) {
		printf("%d %d\n", i+1, ans[i][s]);
		if (ans[i][s] > 0) s = (s + ans[i][s]) % 10;
	}

	return 0;
}


