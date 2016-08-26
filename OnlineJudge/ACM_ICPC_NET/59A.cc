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

int main () {
	char A[101];
	int a;
	gets(A);

	a = strlen(A);
	int lo=0, hi=0;
	for (int i=0; i<a; ++i) {
		if (islower(A[i])) ++lo;
		else ++hi;
	}

	if (lo < hi) for (int i=0; i<a; ++i) A[i] = toupper(A[i]);
	else for (int i=0; i<a; ++i) A[i] = tolower(A[i]);

	printf("%s\n", A);
	return 0;
}


