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

bool compare (const piii& a, const piii& b) {
	return a.second.first != b.second.first ? a.second.first < b.second.first : a.second.second > b.second.second;
}

int main () {
	int n, m;
	scanf("%d%d",&n,&m);
	vector<piii> a, b;
	vi ans;
	for (int i=0; i<m; ++i) {
		int x,y;
		scanf("%d%d", &x, &y);
		if (y < x) b.push_back(make_pair(i+1, make_pair(x,y)));
		else a.push_back(make_pair(i+1, make_pair(x,y)));
	}

	sort(a.begin(), a.end(), compare);
	sort(b.begin(), b.end(), compare);

	int thr = -1;
	for (int i=0; i<b.size(); ++i) {
		if (b[i].second.second > thr) {
			ans.push_back(b[i].first);
			thr = b[i].second.second;
		}
	}

	for (int i=0; i<a.size(); ++i) {
		if (!b.empty() && a[i].second.first >= b[0].second.first) break;
		if (a[i].second.second > thr) {
			ans.push_back(a[i].first);
			thr = a[i].second.second;
		}
	}

	sort(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); ++i)
		printf("%d ", ans[i]);
	return 0;
}


