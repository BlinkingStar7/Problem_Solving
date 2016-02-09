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

struct vector2 {
	double x, y;
	explicit vector2 (double _x=0, double _y=0) : x(_x), y(_y) {}
	double cross (const vector2& rhs) const {
		return x*rhs.y - rhs.x*y;
	}
	double dot (const vector2& rhs) const {
		return x*rhs.x + y*rhs.y;
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}
	bool operator < (const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	double ccw(const vector2& a, const vector2& b) const {
		return a.cross(b);
	}
	double ccw(const vector2& p, const vector2& a, const vector2& b) const {
		return ccw(a-p, b-p);
	}
	bool segmentIntersects (vector2 a, vector2 b, vector2 c, vector2 d) {
		double ab = ccw(a, b, c) * ccw(a, b, d);
		double cd = ccw(c, d, a) * ccw(c, d, b);
		if (ab == 0 && cd == 0) {
			if (b < a) swap (a, b);
			if (d < c) swap (c, d);
			return !(b < c || d < a);
		}
		return ab <=0 && cd <=0;
	}
};


int main () {
	long long N;
	cin >> N;
	while (N--) {
		pair<vector2, vector2> seg, square[4];
		long long x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		seg = make_pair(vector2(x, y), vector2(xx, yy));
		if (seg.first < seg.second) 
			swap(seg.first, seg.second);
		cin >> x >> yy >> xx >> y;
		if (x > xx) swap(x, xx);
		if (y > yy) swap(y, yy);
		square[0] = make_pair(vector2(x, y), vector2(x, yy));
		square[1] = make_pair(vector2(x, yy), vector2(xx, yy));
		square[2] = make_pair(vector2(xx, yy), vector2(xx, y));
		square[3] = make_pair(vector2(xx, y), vector2(x, y));

		bool flag = false;
		for (long long i=0; i<4; ++i) {
			if (seg.first.segmentIntersects (seg.first, seg.second, square[i].first, square[i].second)) {
				 flag = true;
				break;
			}
		}
		int sx = min(seg.first.x, seg.second.x), sxx = max(seg.first.x, seg.second.x);
		int sy = min(seg.first.y, seg.second.y), syy = max(seg.first.y, seg.second.y);

		if (sx > x && sxx < xx && sy > y && syy < yy) flag = true;
		printf("%c\n", flag ? 'T' : 'F');
	}
	return 0;
}

