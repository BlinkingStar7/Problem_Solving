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

long long row1[2010], row2[2010];
int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		++row1[a+b];
		++row2[1000+a-b];
	}
	long long ans = 0;
	for (int i=0; i<2010; ++i) {
		if (row1[i]) ans += (row1[i]*(row1[i]-1))/2;
		if (row2[i]) ans += (row2[i]*(row2[i]-1))/2;
	}
	cout << ans << endl;
	return 0;
}


