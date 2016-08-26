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

const int MAX = 1000005;
char A[MAX];
int N, F[MAX], P[MAX];
int main () {
	gets(A);
	N = strlen(A);

	for (int i=1, m=0; i<N; ++i) {
		while (m && A[m]!=A[i]) m = F[m-1];
		if (A[m]==A[i]) F[i] = ++m;
		P[m]++;
	}

	int m=F[N-1];
	P[m]--;
	while (m) {
		if (P[m]) return 0*printf("%.*s\n", m, A);
		m = F[m-1];
	}
	puts("Just a legend");
	return 0;
}


