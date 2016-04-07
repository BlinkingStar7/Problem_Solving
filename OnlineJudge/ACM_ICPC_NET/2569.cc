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

int n, ans;
bool v[1001];
pii s[1001];

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%d", &s[i].first);
		s[i].second = i;
	}
	sort(s, s+n);
	for (int i=0; i<n; ++i) {
		if (!v[i]) {
			if (s[i].second == i) continue;
			int cur = i, mmin = INF, num = 0;
			while (!v[cur]) {
				v[cur] = true;
				++num;
				ans += s[cur].first;
				mmin = min (mmin, s[cur].first);
				cur = s[cur].second;
			}
			ans += (num-2)*mmin;
		}
	}

	printf("%d\n", ans);

	return 0;
}


