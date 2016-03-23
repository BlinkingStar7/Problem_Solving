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

int w, h, n, mmax = -INF, mmin = INF;

struct point {
	int x, y, id;
};

inline bool inside (int x, int y, int xx, int yy, int X, int Y) {
	return (X>x) && (X<xx) && (Y>y) && (Y<yy);
}

void solve(int x, int y, int xx, int yy, int type, vector<point> p) {
	if (p.size() == 0) {
		mmax = max(mmax, (xx-x)*(yy-y));
		mmin = min(mmin, (xx-x)*(yy-y));
		return ;
	}

	int start = INF, startIndex = -1;
	for (int i=0; i<p.size(); ++i) {
		if (p[i].id < start) {
			start = p[i].id;
			startIndex = i;
		}
	}

	int curX = p[startIndex].x, curY = p[startIndex].y;
	vector<point> a, b;
	if (type) {
		for (int i=0; i<p.size(); ++i) 
			if (i == startIndex) continue;
			else if (inside(x, y, xx, curY, p[i].x, p[i].y))
				a.push_back(p[i]);
			else
				b.push_back(p[i]);

		solve(x, y, xx, curY, 1-type, a);
		solve(x, curY, xx, yy, 1-type, b);
	}
	else {
		for (int i=0; i<p.size(); ++i)
			if (i == startIndex) continue;
			else if (inside(x, y, curX, yy, p[i].x, p[i].y))
				a.push_back(p[i]);
			else
				b.push_back(p[i]);

		solve(x, y, curX, yy, 1-type, a);
		solve(curX, y, xx, yy, 1-type, b);
	}
}

int main () {
	scanf("%d%d%d", &w, &h, &n);
	vector<point> p(n);

	for (int i=0; i<n; ++i) {
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].id = i;
	}

	solve(0, 0, w, h, 1, p);
	printf("%d %d\n", mmax, mmin);
		
	return 0;
}


