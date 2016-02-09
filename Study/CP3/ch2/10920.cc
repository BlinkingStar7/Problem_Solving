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

int sz, p;
int main () {
	while(scanf("%d%d",&sz, &p)) {
		if (sz == 0 && p == 0) break;
		if (p == 1) {
			printf("Line = %d, column = %d.\n", sz/2+1, sz/2+1);
			continue;
		}

		int small = sqrt(p);
		if (small % 2 == 0) --small;
		else if (small * small == p) small -= 2;

		int chunk = (p - small*small - 1) / (small + 1);
		int len = (p - small*small -1) % (small + 1);
		int y, x, base = (sz - small)/2;
		
		if (chunk == 0) { x = base + small - len; y = base + small + 1; }
		if (chunk == 1) { x = base; y = base + small - len; }
		if (chunk == 2) { x = base + len + 1; y = base; }
		if (chunk == 3) { x = base + small + 1; y = base + len + 1; }

		printf("Line = %d, column = %d.\n", y, x);
	}


	return 0;
}

