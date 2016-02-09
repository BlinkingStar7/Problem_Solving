#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;

struct v {
	double x, y;
	explicit v (double _x=0, double _y=0) : x(_x), y(_y) {}
	bool operator == (const v& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const v& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y; }
	v operator - (const v& rhs) const {
		return v(x-rhs.x, y-rhs.y);
	}
	double cross (const v& rhs) const {
		return x*rhs.y - rhs.x*y;
	}
	double ccw (const v& p, const v &a, const v &b) const {
		return (a-p).cross(b-p);
	}
	int segmentIntersections (v a, v b, v c, v d) {
		double ab = ccw(a, b, c)*ccw(a, b, d);
		double cd = ccw(c, d, a)*ccw(c, d, b);
		if (ab == 0 && cd == 0) {
			if (b < a) swap(a, b);
			if (d < c) swap(c, d);

			if (b < c || d < a) return 0;
			else if (!(b == c) && !(d == a)) return 99;
		}
		return ab <= 0 && cd <= 0 ? 1 : 0;
	}
};

int main () {
	int t;
	cin >> t;
	while (t--) {
		pair<v, v> seg, rec[4];
		int x, y, xx, yy, x1, y1, x2, y2;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		rec[0] = make_pair(v(x,y), v(x, yy));
		rec[1] = make_pair(v(x,yy), v(xx, yy));
		rec[2] = make_pair(v(xx,yy), v(xx, y));
		rec[3] = make_pair(v(xx,y), v(x, y));
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		seg = make_pair(v(x1, y1), v(x2, y2));
		int ans = 0;
		for (int i=0; i<4; ++i) 
			ans += seg.first.segmentIntersections (seg.first, seg.second, rec[i].first, rec[i].second);
		
		for (int i=0; i<4; ++i) {
			int x1 = seg.first.x, x2 = seg.second.x, y1 = seg.first.y, y2 = seg.second.y, a = rec[i].first.x, b = rec[i].first.y;
			if (x1 > x2) swap (x1, x2);
			if (y1 > y2) swap (y1, y2);
			if (a>=x1 && a<=x2 && b>=y1 && b<=y2 && (b-y1)*(x2-a) == (y2-b)*(a-x1)) --ans;
		}

		if (ans >= 4) cout << 4 << endl;
		else cout << ans << endl;
	}

	return 0;
}

