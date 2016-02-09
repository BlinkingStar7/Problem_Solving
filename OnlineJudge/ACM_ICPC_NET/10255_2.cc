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

const int INF = 987654321;
struct v {
	int x, y;
	explicit v(int _x=0, int _y=0) : x(_x), y(_y) {}
	bool operator < (const v& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	bool operator ==(const v& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	int s () {
		return x + y;
	}
	v operator - (const v& rhs) const {
		return v(x-rhs.x, y-rhs.y);
	}
	int cross (const v& rhs) const {
		return x*rhs.y - rhs.x*y;
	}
	long long ccw (v a, v b, v c) {
		return (b-a).cross(c-a);
	}
	int parallelIntersection (v a, v b, v c, v d) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		if (ccw(a, b, c) != 0 || b < c || d < a) return 0;	
		return (b == c || d == a) ? 1 : INF;
	}

	int segmentIntersection (v a, v b, v c, v d) {
		if ((b-a).cross(d-c) ==  0)
			return parallelIntersection ( a,  b,  c,  d);

		long long ab = ccw(a, b, c) * ccw(a, b, d);
		long long cd = ccw(c, d, a) * ccw(c, d, b);
		return ab <= 0 && cd <= 0 ? 1 : 0;
	}
};
	
int main () {
	int t;
	cin >> t;
	while(t--) {
		int x,xx,y,yy,x1,x2,y1,y2;
		pair<v, v> seg, rec[4];
		scanf("%d%d%d%d%d%d%d%d", &x,&y,&xx,&yy,&x1,&y1,&x2,&y2);
		seg = make_pair(v(x1,y1), v(x2,y2));
		if (seg.second < seg.first) swap(seg.first, seg.second);
		rec[0] = make_pair(v(x,y), v(x,yy));
		rec[1] = make_pair(v(x,yy), v(xx,yy));
		rec[2] = make_pair(v(xx,yy), v(xx,y));
		rec[3] = make_pair(v(xx,y), v(x,y));

		int ans=0;
		for (int i=0; i<4; ++i) {
			int x1,x2,y1,y2,a,b;
			x1 = seg.first.x, x2 = seg.second.x, y1 = seg.first.y, y2 = seg.second.y;
			a = rec[i].first.x, b = rec[i].first.y;
			ans += seg.first.segmentIntersection(seg.first, seg.second, rec[i].first, rec[i].second);
			if ((b-y1)*(x2-a) == (a-x1)*(y2-b) && (a+b)>=(x1+y1) && (a+b) <=(x2+y2))
				ans -= 1;
		}

		if (ans > 4) ans = 4;
		printf("%d\n", ans);
			
	}
	return 0;
}

