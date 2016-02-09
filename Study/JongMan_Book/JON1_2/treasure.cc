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
#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

struct P {
	double x, y;
	P () {}
	P (double x, double y) : x(x), y(y) {}
	P operator + (const P& rhs) const {
		return P(x+rhs.x, y+rhs.y);
	}
	P operator - (const P& rhs) const {
		return P(x-rhs.x, y-rhs.y);
	}
	P operator * (double k) const {
		return P(x*k, y*k);
	}
	double cross (const P& rhs) const {
		return x*rhs.y - y*rhs.x;
	}
} Clip[4];
struct L {
	P a, b;
	L () {}
	L (P& a, P& b) : a(a), b(b) {}
};

int ccw (P&a , P&b, P&c) {
	double k = (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
	return k > 0 ? 1 : k == 0 ? 0 : -1;
}

double computeArea(vector<P> p) {
	double ret=0;
	for (int i=0; i<p.size(); ++i) {
		ret += p[i].x*p[(i+1)%p.size()].y - p[i].y*p[(i+1)%p.size()].x;
	}
	return abs(ret)/2.0;
}

P lineIntersection(L clipEdge, L curEdge) {
	double det = (clipEdge.b - clipEdge.a).cross(curEdge.b - curEdge.a);
	P ret = clipEdge.a + (clipEdge.b - clipEdge.a)*((curEdge.a - clipEdge.a).cross(curEdge.b - curEdge.a)/det);
	return ret;
}

int testNum, N;
int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> Clip[0].x >> Clip[0].y >> Clip[2].x >> Clip[2].y >> N;
		if (Clip[2].x < Clip[0].x) swap(Clip[2].x, Clip[0].x);
		if (Clip[2].y < Clip[0].y) swap(Clip[2].y, Clip[0].y);
		Clip[1].x = Clip[2].x, Clip[1].y = Clip[0].y;
		Clip[3].x = Clip[0].x, Clip[3].y = Clip[2].y;
		vector<P> Poly;
		for (int i=0; i<N; ++i) {
			double x, y;
			cin >> x >> y;
			Poly.push_back(P{x, y});
		}

		for (int i=0; i<4; ++i) {
			vector<P> newPoly;
			L clipEdge(Clip[i], Clip[(i+1)%4]);
			DEBUG_PRINT(("Testing (%lf, %lf) - (%lf, %lf)\n", clipEdge.a.x, clipEdge.a.y, clipEdge.b.x, clipEdge.b.y));
			for (int j=0; j<Poly.size(); ++j) {
				L curEdge(Poly[j], Poly[(j+1)%Poly.size()]);
				DEBUG_PRINT(("\n\tTesting (%lf, %lf) - (%lf, %lf)\n", curEdge.a.x, curEdge.a.y, curEdge.b.x, curEdge.b.y));
				if (ccw(clipEdge.a, clipEdge.b, curEdge.a) >= 0) {
					DEBUG_PRINT(("\t\tStart vertex inside, "));
					if (ccw(clipEdge.a, clipEdge.b, curEdge.b) >= 0) {
						newPoly.push_back(curEdge.b);
						DEBUG_PRINT(("End vertex inside\n"));
					}
					else {
						newPoly.push_back(lineIntersection(clipEdge, curEdge));
						DEBUG_PRINT(("End vertex outside\n"));
					}
					DEBUG_PRINT(("\t\t\t(%lf, %lf) inserted\n", newPoly.back().x, newPoly.back().y));
				}
				else {
					DEBUG_PRINT(("\t\tStart vertex outside, "));
					if (ccw(clipEdge.a, clipEdge.b, curEdge.b) >= 0) {
						DEBUG_PRINT(("End vertex inside\n"));
						if (ccw(clipEdge.a, clipEdge.b, curEdge.b) > 0) {
							newPoly.push_back(lineIntersection(clipEdge, curEdge));
							DEBUG_PRINT(("\t\t\t(%lf, %lf) inserted ", newPoly.back().x, newPoly.back().y));
						}
						newPoly.push_back(curEdge.b);
						DEBUG_PRINT(("\t\t\t(%lf, %lf) inserted\n", newPoly.back().x, newPoly.back().y));
					}
					else {
						DEBUG_PRINT(("End vertex outside\n"));
					}
				}
			}
			Poly = newPoly;
		}

		printf("%.10lf\n", computeArea(Poly));
	}

	return 0;
}

