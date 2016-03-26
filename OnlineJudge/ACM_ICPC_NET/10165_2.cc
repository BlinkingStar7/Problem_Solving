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

struct bus {
	int a, b, index;
};
int n, m;
vi ans;
vector<bus> group[2];

bool comp (const bus& x, const bus& y) {
	return x.a != y.a ? x.a < y.a : x.b > y.b;
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		int a, b;
		scanf("%d%d",&a, &b);
		if (a < b) group[0].push_back({a, b, i+1});
		else group[1].push_back({a, b+n, i+1});
	}
	sort(group[0].begin(), group[0].end(), comp);
	sort(group[1].begin(), group[1].end(), comp);

	int bb = -1;
	for (int i=0; i<group[1].size(); ++i) {
		if (group[1][i].b > bb) {
			bb = group[1][i].b;
			ans.push_back(group[1][i].index);
		}
	}

	bb -= n;
	for (int i=0; i<group[0].size(); ++i) {
		if (group[0][i].a >= group[1][0].a) break;
		if (group[0][i].b > bb) {
			bb = group[0][i].b;
			ans.push_back(group[0][i].index);
		}
	}

	sort(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); ++i)
		printf("%d ", ans[i]);
	return 0;
}


