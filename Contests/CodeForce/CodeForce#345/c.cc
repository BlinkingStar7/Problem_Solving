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

int n;
pii p[200001];

bool compare (const pii& a, const pii& b) {
	return a.second != b.second ? a.second < b.second : a.first < b.first;
}

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d%d", &p[i].first, &p[i].second);

	long long ans = 0;
	sort(p, p+n);

	long long num = 1;
	for (int i=1; i<n; ++i) {
		if (p[i].first == p[i-1].first) ++num;
		else {
			ans += num*(num-1)/2;
			num = 1;
		}
	}
	ans += num*(num-1)/2;

	sort(p, p+n, compare);

	num = 1;
	for (int i=1; i<n; ++i) {
		if (p[i].second == p[i-1].second) ++num;
		else {
			ans += num*(num-1)/2;
			num = 1;
		}
	}
	ans += num*(num-1)/2;

	num = 1;
	for (int i=1; i<n; ++i) {
		if (p[i].first == p[i-1].first && p[i].second == p[i-1].second) ++num;
		else {
			ans -= num*(num-1)/2;
			num = 1;
		}
	}
	ans -= num*(num-1)/2;
	printf("%lld\n", ans);
	return 0;
}


