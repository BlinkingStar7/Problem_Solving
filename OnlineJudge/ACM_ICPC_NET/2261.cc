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
vpi point;

inline int dist (pii a, pii b) { return (b.frist-a.first)*(b.frist-a.first)+(b.second-a.second)*(b.second-a.second); }

int solve(int start, int end) {
	if (start == end) return INF;
	else if (start + 1 == end) return dist (point[start], point[end]);

	int mid = (start+end)/2;
	int d = min(solve(start, mid), solve(mid+1, end));
	int midx = point[mid].first;
	vpi cand(lower_bound(
int main () {
	scanf("%d", &n);
	point.assign(n);
	for (int i=0; i<n; ++i)
		scanf("%d%d",&point[i].first, &point[i].second);
	sort(point, point+n);
	
	printf("%d\n", solve(0, n-1));
	return 0;
}


