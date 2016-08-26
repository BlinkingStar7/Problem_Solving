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

int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
		scanf("%d", p+i);
	for (int i=0; i<n; ++i)
		scanf("%d", h+i);

	for (int i=0; i<n; ++i) {
		dy[i] = i == 0 ? h[i] : h[i] - h[i-1];
		dx[i] = i == 0 ? p[i] : p[i] - p[i-1];
	}

	double lo = -1e-10, hi = 1e7;
	for (int i=0; i<100; ++i) {
		double mid = (lo + hi)/2;
		double cand = -1;
		for (int j=0; j<n; ++j) {
			

	return 0;
}


