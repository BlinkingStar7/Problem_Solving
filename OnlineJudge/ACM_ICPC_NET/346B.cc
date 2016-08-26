#include <bits/stdc++.h>
using namespace std;
#define PI (2*acos(0.0))
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

const int MAX = 101;
int a, b, v, memo[101][101][101], Z[MAX], best[101][101][101];
char A[MAX], B[MAX], V[MAX];

int Solve (int s1, int s2, int m) {
	if (m == v) return -INF;
	if (s1 == a || s2 == b) return 0;

	int &ret = memo[s1][s2][m];
	if (ret != -1) return ret;

	int r = Solve(s1+1, s2, m), rr = Solve(s1, s2+1, m);
	if (r > rr) {
		ret = r;
		best[s1][s2][m] = 0;
	}
	else {
		ret = rr;
		best[s1][s2][m] = 1;
	}

	if (A[s1] == B[s2]) {
		int mm = m;
		while (mm && A[s1] != V[mm]) mm = Z[mm-1];
		if (A[s1] == V[mm]) ++mm;

		int rrr = Solve(s1+1, s2+1, mm)+1;
		if (rrr > ret) {
			ret = rrr;
			best[s1][s2][m] = 2;
		}
	}

	return ret;
}

void printAns (int s1, int s2, int m) {
	if (s1 == a || s2 == b) return;

	if (best[s1][s2][m] == 2) { 
		putchar(A[s1]);
		
		int mm = m;
		while (mm && A[s1] != V[mm]) mm = Z[mm-1];
		if (A[s1] == V[mm]) ++mm;
	
		return printAns(s1+1, s2+1, mm); 
	}
	else if (best[s1][s2][m] == 1) return printAns(s1, s2+1, m);
	else return printAns(s1+1, s2, m);
}

int main () {
	gets(A);
	gets(B);
	gets(V);

	a = strlen(A);
	b = strlen(B);
	v = strlen(V);

	for (int i=1, m=0; i<v; ++i) {
		while (m && V[m] != V[i]) m = Z[m-1];
		if (V[m] == V[i]) Z[i] = ++m;
	}

	memset(memo, -1, sizeof(memo));
	int ret = Solve(0, 0, 0);
	if (!ret) return 0*printf("0\n");

	printAns(0, 0, 0);
	return 0;
}


