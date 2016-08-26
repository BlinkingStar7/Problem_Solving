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

ll A[4], sum;
char ans[1000005];
ll Solve(ll x) {
	ll sq = 8*x+1;
	ll root = sqrt(sq);
	if (root*root != sq) return -1;
	
	return (root+1)/2;
}

inline int fail() {
	return 0*printf("Impossible\n");
}

int main () {
	for (int i=0; i<4; ++i) {
		scanf("%lld", A+i);
		sum += A[i];
	}


	if (!A[0] && !A[1] && !A[2]) {
		int ret = Solve(A[3]);
		if (ret == -1) return fail();
		else cout << string(ret, '1') << '\n';
		return 0;
	}
	if (!A[1] && !A[2] && !A[3]) {
		int ret = Solve(A[0]);
		if (ret == -1) return fail();
		else cout << string(ret, '0') << '\n';
		return 0;
	}

	int numZero = Solve(A[0]), numOne = Solve(A[3]), numTotal;
	if (numZero == -1 || numOne == -1) return fail();

	numTotal = numZero + numOne;
	if (Solve(sum) != numTotal) return fail();

	for (int i=0; i<numTotal; ++i) {
		if (A[1] > 0 && A[1] >= numOne) {
			if (numOne == 0 || numZero == 0) return fail();
			ans[i] = '0';
			--numZero;
			A[1] -= numOne;
		}
		else if (A[1] > 0) {
			if (numOne == 0) return fail();
			ans[i] = '1';
			--numOne;
		}
		else if (A[1] == 0) {
			int cur = i;
			while (numOne--) ans[cur++] = '1';
			while (numZero--) ans[cur++] = '0';
			break;
		}
	}

	printf("%s\n", ans);
	return 0;
}


