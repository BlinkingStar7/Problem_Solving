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

int N;
struct segment {
	int x, y, xx, yy;
};

void getPoint (int &iden, int &len, int m1, int m3) {
	int x, y;
	if (iden == 1 || iden == 2) x = len;
	else x = (iden == 3 ? 0 : m1);
	if (iden == 3 || iden == 4) y = -len;
	else y = (iden == 1 ? 0 : -m3);
	
	iden = x;
	len = y;
}

inline int X(pair<int ,int>& a, pair<int, int>& b) {
	return a.first*b.second - a.second*b.first;
}

bool cross (segment& a, segment&b) {
	pair<int, int> r = make_pair(a.xx-a.x, a.yy-a.y);
	pair<int, int> s = make_pair(b.xx-b.x, b.yy-b.y);
	pair<int, int> qp = make_pair(b.x-a.x, b.y-a.y);

#ifdef DEBUG
	printf("%d %d %d %d to %d %d %d %d\n", a.x, a.y, a.xx, a.yy, b.x, b.y, b.xx, b.yy);
	printf("rXs : %d, qpXr : %d, qpXs : %d\n", X(r, s), X(qp, r), X(qp, s));
#endif
	if (X(r, s) == 0) { 
		if (X(qp, r) == 0) {
			if (max(a.x, a.xx) >= min(b.x, b.xx) && max(b.x, b.xx) >= min(a.x, a.xx)
			 && max(a.y, a.yy) >= min(b.y, b.yy) && max(b.y, b.yy) >= min(a.y, a.yy))
				return true;
		}
	}
	else {
		int a = X(qp, r), b = X(r, s), c= X(qp, s);
		if (a*b < 0 || b*c <0) return false;
		return (b > 0 ? (a <= b && c <= b) : (a >= b && c >= b));
	}
}

int main () {
	cin >> N;
	N/=2;
	vector<segment> seg(N);
	int M1=0, M3=0;
	for (int i=0; i<N; ++i) {
		scanf("%d%d%d%d", &seg[i].x, &seg[i].y, &seg[i].xx, &seg[i].yy);
		if (seg[i].x == 1 || seg[i].x == 2) M1 = max (M1, seg[i].y);
		else M3 = max (M3, seg[i].y);
		if (seg[i].xx == 1 || seg[i].xx == 2) M1 = max (M1, seg[i].yy);
		else M3 = max (M3, seg[i].yy);
	}

	++M1, ++M3;

	for (int i=0; i<N; ++i) {
		getPoint(seg[i].x, seg[i].y, M1, M3);
		getPoint(seg[i].xx, seg[i].yy, M1, M3);
	}

	int ans = 0;
	vector<int> M(N, 0);
	for (int i=0; i<N; ++i) {
		for (int j=i+1; j<N; ++j) {
			if (cross(seg[i], seg[j])) {
				++ans;
				++M[i], ++M[j];
			}
		}
	}

	printf("%d\n", ans);
	int a=0;
	for (int i=0; i<N; ++i)
		a = max(a, M[i]);
	printf("%d\n", a);

	return 0;
}

