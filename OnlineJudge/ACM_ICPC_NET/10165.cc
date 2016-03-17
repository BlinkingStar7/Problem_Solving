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
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i) {
		scanf("%d%d", &p[i].first, &p[i].second);
		if (p[i].first > p[i].second) p[i].second += n;
		if (p[i].second > best) 
		p[i].second = -p[i].second;
	}


	return 0;
}


