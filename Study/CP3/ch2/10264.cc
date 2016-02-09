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
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int pot[1<<15];
int main () {
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(pot, 0, sizeof(pot));
		for (int cur=0; cur<1<<n; ++cur) {
			int t;
			scanf("%d", &t);

			for (int i=0; i<n; ++i) 
				pot[cur^(1<<i)] += t;
		}

		int ans=-INF;
		for (int cur=0; cur<1<<n; ++cur) {
			for (int i=0; i<n; ++i)
				ans = max(ans, pot[cur^(1<<i)] + pot[cur]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

