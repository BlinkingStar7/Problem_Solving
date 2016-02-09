#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <bitset>
using namespace std;
#define PI 2*acos(0.0)
#define IFN 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	int s, b;
	while (scanf("%d%d",&s,&b) != EOF) {
		if (s == 0 && b == 0) break;
		vb liven(s+2, true);
		vi L(s+2), R(s+2);
		
		for (int i=1; i<=s; ++i) {
			L[i] = i-1;
			R[i] = i+1;
		}

		for (int i=0; i<b; ++i) {
			int l, r, ansL, ansR;
			scanf("%d%d",&l,&r);
			liven[l] = liven[r] = false;
			ansL = liven[l-1] ? l-1 : L[l-1];
			ansR = liven[r+1] ? r+1 : R[r+1];
			L[ansR-1] = ansL;
			R[ansL+1] = ansR;

			ansL == 0 ? printf("* ") : printf("%d ", ansL);
			ansR == s+1 ? printf("*\n") : printf("%d\n", ansR);
		}
		puts("-");

	}
	return 0;
}

