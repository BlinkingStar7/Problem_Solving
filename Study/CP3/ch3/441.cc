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

int k;
void solve(vi &list, vi &sel, int last) {
	if (sel.size() == 6) {
		for (int i=0; i<5; ++i)
			printf("%d ", sel[i]);
		printf("%d\n", sel[5]);
		return;
	}

	if (last == list.size()-1) return;

	for (int next = last+1; next < list.size(); ++next) {
		sel.push_back(list[next]);
		solve(list, sel, next);
		sel.pop_back();
	}
}


int main () {
	bool first = true;
	while(scanf("%d", &k)) {
		if (k == 0) break;

		vi list(k), sel;
		for (int i=0; i<k; ++i)
			scanf("%d", &list[i]);

		if (first) first = false;
		else puts("");
		solve(list, sel, -1);
		
	}

	return 0;
}

