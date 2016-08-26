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
typedef long long ll;
typedef unsigned long long ull;

int main () {
	int n;
	scanf("%d", &n);
	vpii v;
	for (int i=0; i<n; ++i) {
		int t;
		scanf("%d", &t);
		v.push_back(make_pair(t, i));
	}

	sort(v.begin(), v.end());

	for (int i=0; i<n/2; ++i) {
		printf("%d %d\n", v[i].second+1, v[n-i-1].second+1);
		}




	return 0;
}


