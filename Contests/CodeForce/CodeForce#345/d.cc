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

int n, a, b, t, num[512345];

long long c (int left, int right) {
	long long x = right + left + 1;
	return x + (x-1)*a + min(right, left)*a + (num[right] + num[n-1] - num[n-left-1])*b;
}

int main () {
	scanf("%d%d%d%d ", &n,&a,&b,&t);

	for (int i=0; i<n; ++i) {
		char ch;
		scanf("%c", &ch);
		if (ch == 'w') num[i] = (i == 0 ? 0 : num[i-1]) + 1;
		else num[i] = (i == 0 ? 0 : num[i-1]);
	}

	int left = 0, right = n-1, ans = 0;

	while (1) {
		int x = right + left + 1;
		if (x > n || right < 0) break;

		long long cost = c(left, right);
		if (cost > t) { --right; continue;} 
		ans = max(ans, x);
		++left;
	}

	printf("%d\n", ans);

	return 0;
}


