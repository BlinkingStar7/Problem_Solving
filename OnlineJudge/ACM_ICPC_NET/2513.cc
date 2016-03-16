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
	int n, k, s, num[100001] = {};
	scanf("%d%d%d", &n,&k,&s);
	for (int i=0; i<n; ++i) {
		int a, b;
		scanf("%d%d", &a,&b);
		num[a] = b;
	}

	int sum = 0, ans = 0, bef = -1;
	for (int i=0; i<s; ++i) {
		if (num[i]) {
			sum = (num[i] += sum);
			int t = (num[i]-1)/k;
			ans += 2*(s-i)*(t-bef);
			bef = t;
		}
	}

	sum = 0, bef = -1;
	for (int i=100000; i>s; --i) {
		if (num[i]) {
			sum = (num[i] += sum);
			int t = (num[i]-1)/k;
			ans += 2*(i-s)*(t-bef);
			bef = t;
		}
	}

	printf("%d\n", ans);
	return 0;
}


