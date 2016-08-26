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

int x[4], y[4];

int cross (pii &a, pii &b) {
	return a.first*b.second - a.second*b.first;
}

int main () {
	
	for (int i=0; i<4; ++i)
		scanf("%d %d", x+i, y+i);

	pii p = {x[0], y[0]}, r = {x[1]-x[0], y[1]-y[0]};
	pii q = {x[2], y[2]}, s = {x[3]-x[2], y[3]-y[2]};
	pii qp = {x[2]-x[0], y[2]-y[0]};

	if (cross (r, s)) {
		while (1) {
		if (cross (qp, s) * cross (r, s) <= 0) break;
		if (cross (qp, r) * cross (r, s) <= 0) break;

		if (abs(cross(qp, s)) >= abs(cross(r, s))) break;
		if (abs(cross(qp, r)) >= abs(cross(r, s))) break;

		printf("1\n");
		return 0;
		}
	}
	printf("0\n");


	return 0;
}


