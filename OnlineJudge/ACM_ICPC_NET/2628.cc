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
	int h, w; scanf("%d%d", &w, &h);
	int n; scanf("%d", &n);
	vi a, b;
	for (int i=0; i<n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x) b.push_back(y);
		else a.push_back(y);
	}

	a.push_back(h); b.push_back(w);

	sort(a.begin(), a.end()); sort(b.begin(), b.end());
	a.erase(unique(a.begin(), a.end()), a.end()); b.erase(unique(b.begin(), b.end()), b.end());

	int befa=0, befb = 0, ans = -INF;
	for (int i=0; i<a.size(); ++i) {
		for (int j=0; j<b.size(); ++j) {
			ans = max (ans, (a[i] - befa)*(b[j] - befb));
			befb = b[j];
		}
		befa = a[i];
		befb = 0;
	}

	printf("%d\n", ans);
	return 0;
}


