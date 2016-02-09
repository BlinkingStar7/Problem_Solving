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
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while(0)
#endif
const double INF = 100000;
struct P {
	double x, y; 
	P operator - (const P& rhs) const { return P{x-rhs.x, y-rhs.y};}
	bool operator < (const P& rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y;}
};

struct L {
	P a, b;
	L () {}
	L (P& a, P& b) : a(a), b(b) {}
};

int ccw (P& A, P& B, P& C) {
	double k = (B-A).x*(C-A).y - (C-A).x*(B-A).y;
	return k > 0 ? 1 : k == 0 ? 0 : -1;
}

P getPoint (int type, int len ){
	if (type == 1) return P {len, INF};
	if (type == 2) return P {len, 0};
	if (type == 3) return P {0, INF-len};
	if (type == 4) return P {INF, INF-len};
}

bool lineIntsc (L& A, L& B) {
	if (ccw(A.a, A.b, B.a) == 0 && ccw(A.a, A.b, B.b) == 0) {
		if (A.b < A.a) swap(A.a, A.b);
		if (B.b < B.a) swap(B.a, B.b);
		if ((A.a < B.a && B.b < A.b) || (B.a < A.a && A.b < B.b)) return false;
		return !(A.b < B.a || B.b < A.a);
	}
	return !(ccw(A.a, A.b, B.a) == ccw(A.a, A.b, B.b) || ccw(B.a, B.b, A.a) == ccw(B.a, B.b, A.b));
}

int N;
int main () {
	cin >> N;
	N/=2;
	vector<L> line(N);
	vector<int> num(N, 0);
	for (int i=0; i<N; ++i) {
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		P t1 = getPoint(a, b);
		P t2 = getPoint(c, d);
		line[i] = L(t1, t2);
	}

	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			if (i == j) continue;
			if (lineIntsc(line[i], line[j])) {
				DPRINTF (("%d intresect with %d\n",i+1, j+1));
				num[i]++;
			}
		}
	}
	int total=0, Max=0;
	for (int i=0; i<N; ++i) {
		Max = max (Max, num[i]);
		total += num[i];
	}

	cout << total/2 << endl;
	cout << Max << endl;

	return 0;
}

