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
	int t;
	scanf("%d", &t);
	for (int tn=1; tn<=t; ++tn) {
		printf("Case #%d:", tn);
		int n, a[27], sum = 0;
		priority_queue<pii> pq;

		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			int t; scanf("%d", &t);
			sum += t;
			pq.push_back(make_pair(t, i));
		}

		while (!pq.empty()) {
			int  



	return 0;
}


