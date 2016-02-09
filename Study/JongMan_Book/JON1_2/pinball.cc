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

int testNum, N;
const double EPSILON = 1e-9, INF = 1e200;

struct v {
	double x, y;
	v () {}
	v (double x, double y) : x(x), y(y) {}
	v operator + (const v& rhs) const {
		return v(x+rhs.x, y+rhs.y);
	}
	v operator - () const {
		return v(-x, -y);
	}

	v operator - (const v& rhs) const {
		return v(x-rhs.x, y-rhs.y);
	}
	v operator * (double k) const {
		return v(k*x, k*y);
	}
	double norm () const {
		return hypot(x, y);
	}
	v normalize() const{
		return v(x/norm(), y/norm());
	}
	double dot (const v& rhs) const {
		return x*rhs.x + y*rhs.y;
	}
	v project (const v& rhs) const {
		v r = rhs.normalize();
		return r*(this->dot(r));
	}

};
v operator * (double k, const v& rhs) {
	return rhs*k;
}
vector<double> solve2 (double a, double b, double c) {
	double d = b*b - 4*a*c;
	if (d < -EPSILON) return vector<double> ();
	if (d < EPSILON) return vector<double> (1, -b/(2*a));
	vector<double> ret;
	ret.push_back((-b-sqrt(d))/(2*a));
	ret.push_back((-b+sqrt(d))/(2*a));
	return ret;
}

double hitCircle (v here, v dir, v center, double r) {
	double a = dir.dot(dir);
	double b = 2*(here-center).dot(dir);
	double c = center.dot(center) + here.dot(here) - 2.0*center.dot(here) - r*r;
	vector<double> sols = solve2 (a, b, c);
	if (sols.empty() || sols[0] < EPSILON) return INF;
	return sols[0];
}

v getDir (v d, v c, v t) {
	return (d - d.project(t-c)*2).normalize();
}
pair<v, double> circle[51];

int main () {
	cin >> testNum;

	while (testNum--) {
		double x,y,dx,dy;
		scanf("%lf%lf%lf%lf%d",&x,&y,&dx,&dy,&N);
		v curPos(x, y);
		v curDir(dx, dy);
		curDir = curDir.normalize();
		for (int i=0; i<N; ++i) {
			scanf("%lf%lf%lf",&circle[i].first.x, &circle[i].first.y, &circle[i].second);
			circle[i].second += 1;
		}
		
		for (int i=0; i<10; ++i) {
			double cand = INF*0.5;
			int index = -1;
			for (int j=0; j<N; ++j) {
				double temp = hitCircle(curPos, curDir, circle[j].first, circle[j].second);
				if (temp < cand) {
					cand = temp;
					index = j;
				}
			}
			if (index == -1) break;
			else printf("%d ", index);

			curPos = curPos + cand*curDir;
			curDir = getDir(curDir,circle[index].first, curPos);			

		}

	}


	return 0;
}

