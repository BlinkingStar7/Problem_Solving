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
	int ans=0, n;
	scanf("%d", &n);

	for (int a=1; a<=n/3; ++a) 
		for (int b=max(a, (n/2-a+1)); b<=n-a-b; ++b) {
			++ans;
		}
	printf("%d\n", ans);
	return 0;
}


