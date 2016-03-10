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

int a[1234];
int main () {
	int n; cin >> n;
	for (int i=0; i<n; ++i) {
		int t; scanf("%d", &t);
		a[t]++;
	}

	int ans = 0;
	while (1) {
		bool flag = false;
		int num = 0;
		for (int i=1; i<=1000; ++i) 
			if (a[i]) {
				flag = true;
				++num;
				a[i]--;
			}
		if (!flag) break;
		ans += num-1;
	}
	printf("%d\n", ans);
	return 0;
}


