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
	int n, maxVal = -1;
	pii p[1001];
	scanf("%d", &n);
	for (int i=0; i<n; ++i) { 
		scanf("%d%d", &p[i].first, &p[i].second);
		maxVal = max(maxVal, p[i].second);
	}

	sort(p, p+n);
	int h=p[0].second, ans=0, a, b;
	for (int i=0; i<n; ++i)
		if (p[i].second == maxVal) { a = i; break; }
	for (int i=n-1; i>=0; --i)
		if (p[i].second == maxVal) { b = i; break; }

	for (int i=1; i<=a; ++i) {
		ans += h*(p[i].first - p[i-1].first);
		h = max(h, p[i].second);
	}

	h=p[n-1].second;
	for (int i=n-2; i>=b; --i) {
		ans += h*(p[i+1].first - p[i].first);
		h = max(h, p[i].second);
	}
	
	ans += maxVal*(p[b].first-p[a].first+1);
	printf("%d\n", ans);
	return 0;
}


