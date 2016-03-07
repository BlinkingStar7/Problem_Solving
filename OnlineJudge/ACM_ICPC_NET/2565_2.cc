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
	int n; scanf("%d", &n);
	pii wire[101];
	for (int i=0; i<n; ++i)
		scanf("%d%d", &wire[i].first, &wire[i].second);
	sort(wire, wire+n);

	int arr[101], len=0;
	for (int i=0; i<n; ++i) {
		int val = wire[i].second;
		int pos = lower_bound(arr, arr+len, val) - arr;
		arr[pos] = val;
		if (pos == len) ++len;
	}
	
	printf("%d\n", n-len);
	return 0;
}


