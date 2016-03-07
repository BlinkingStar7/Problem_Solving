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

int n, m, to[300];
string base[2], cand[101];

int main () {
	to['1'] = '3';
	to['2'] = '4';
	to['3'] = '1';
	to['4'] = '2';

	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int t;
		scanf("%d", &t);
		base[0] += '0' + t;
	}
	
	base[0] += base[0];

	for (int i=0; i<2*n; ++i)
		base[1] += to[base[0][2*n-i-1]];

	scanf("%d", &m);
	vi ans;
	for (int j=0; j<m; ++j) {
		for (int i=0; i<n; ++i) {
			int t;
			scanf("%d", &t);
			cand[j] += '0' + t;
		}
		
		if (base[0].find(cand[j]) != string::npos || base[1].find(cand[j]) != string::npos) ans.push_back(j);
	}

	printf("%d\n", ans.size());
	for (int i=0; i<ans.size(); ++i)
		for (int j=0; j<n; ++j)
			printf("%c%c", cand[ans[i]][j], j == n-1 ? '\n' : ' ');


	return 0;
}


