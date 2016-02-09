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
	int n;
	while(scanf("%d", &n) != EOF) {
		DPRINTF(("n = %d\n", n));
		vb dif(n-1, false);
		int prev;
		scanf("%d", &prev);
		bool flag = true;
		for (int i=0; i<n-1; ++i) {
			int cur;
			scanf("%d", &cur);
			if (!flag) continue;
			if (abs(cur-prev) >= n || abs(cur-prev) == 0) 
				flag = false;

			if (dif[abs(cur-prev)])
				flag = false;


			dif[abs(cur-prev)] = true;
			prev = cur;
		}
		if (flag) printf("Jolly\n");
		else printf("Not jolly\n");
	}

	return 0;
}

