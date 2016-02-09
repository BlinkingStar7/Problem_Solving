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

int N;
void solve (int n, int a, int b, int c) {
	if (n == 0) return;
	
	solve(n-1, a, c, b);
	printf("%d %d\n", a, c);
	solve(n-1, b, a, c);
}
int main () {
	scanf("%d", &N);

	printf("%d\n", (1<<N) - 1);
	solve(N, 1, 2, 3);
	return 0;
}


