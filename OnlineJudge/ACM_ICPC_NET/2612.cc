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

int a, b, memo[1005][1005][2];
char A[1005], B[1005];

int Solve (int p, int pp, bool s) {
	if (p == a || pp == b) return 0;

	int &ret = memo[p][pp][s];
	if (ret != -INF) return ret;

	if (s) {
		ret = max (Solve(p+1, pp, s) -2, Solve(p, pp+1, s) -2);
		ret = max (ret, Solve(p+1, pp+1, s) + (A[p] == B[pp] ? 3 : -2));
		ret = max (ret, 0);
	}
	else {
		ret = max (Solve(p+1, pp, s), Solve(p, pp+1, s));
		ret = max (ret, Solve(p, pp, true));
	}
	return ret;
}

void Construct (int p, int pp, bool s) {
	int &ret = memo[p][pp][s];
	if (p == a || pp == b || ret == 0) return;

	if (!s) {
		if (Solve(p+1, pp, s) > Solve(p, pp+1, s)) return Construct(p+1, pp, s);
		else return Construct(
int main () {
	scanf("%d ", &a);
	gets(A);
	scanf("%d ", &b);
	gets(B);

	for (int i=0; i<a; ++i) for (int j=0; j<b; ++j) for (int k=0; k<2; ++k) memo[i][j][k] = -INF;
	printf("%d\n", Solve(0, 0, false));
	return 0;
}
