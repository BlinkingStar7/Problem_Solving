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
	v () {}
	v (double x, double y) : x(x), y(y) {}
	bool operator < (const v& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	bool operator == (const v& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	v operator - (const v& rhs) const {
		return v(x-rhs.x, y-rhs.y);
	}
	v operator + (const v& rhs) const {
		return v(x+rhs.x, y+rhs.y);
	}
	double norm() {
		return hypot(x, y);
	}
};
int ccw (v a, v b, v c) {
	double t = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
	return t>0?1:t==0?0:-1;
}

typedef vector<v> polygon;
int testNum, N;

polygon giftWrap(const polygon& point) {
	int n=point.size();
	vector<bool> included(n,false);
	polygon ret;
	v pivot = *min_element(point.begin(), point.end());
	ret.push_back(pivot);
	while(1) {
		v cur = ret.back(), cand = point[0];
		for (int i=0; i<n; ++i) {
			double cross = ccw(cur, cand, point[i]);
			double dist = (cand - cur).norm() - (point[i]-cur).norm();
			if (cross > 0 || (cross == 0 && dist < 0))
				cand = point[i];
		}
		if (cand == pivot) break;
		ret.push_back(cand);
	}
	return ret;
}

bool segmentIntersection(v a, v b, v c , v d) {
	if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0) {
		if (b<a) swap(a,b);
		if (d<c) swap(c,d);
		return !(b<c || d<a);
	}

	return !(ccw(a, b, c) == ccw(a, b, d) || ccw(c, d, a) == ccw(c, d, b));
}

bool isInside(v p, const polygon& poly) {
	int i, j, c = 0;
	for (int i=0, j=poly.size()-1; i<poly.size(); j=i++)
		if (((poly[i].y > p.y) != (poly[j].y > p.y)) &&
			(p.x < (p.y-poly[i].y)*(poly[j].x-poly[i].x)/(poly[j].y-poly[i].y)+poly[i].x))
			c = !c;
	return c;
}
bool polygonIntersection(const polygon& p1, const polygon& p2) {
	if (isInside(p1[0], p2) || isInside(p2[0], p1))
		return true;
	for (int i=0; i<p1.size(); ++i) {
		for (int j=0; j<p2.size(); ++j) {
			if (segmentIntersection(p1[i], p1[(i+1)%p1.size()], p2[j], p2[(j+1)%p2.size()]))
				return true;
		}
	}
	return false;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;
		polygon nerd[2];
		for (int i=0; i<N; ++i) {
			int n, shoe, type;
			scanf("%d%d%d",&n,&shoe,&type);
			nerd[n].push_back(v(shoe, type));
		}

		polygon poly[2];
		for (int i=0; i<2; ++i)
			poly[i] = giftWrap(nerd[i]);

		if (polygonIntersection(poly[0], poly[1]))
			printf("THEORY IS INVALID\n");
		else
			printf("THEORY HOLDS\n");

	}


	return 0;
}

