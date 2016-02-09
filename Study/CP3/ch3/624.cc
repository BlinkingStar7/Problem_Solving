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

int ansVal=0;
vi ans;
int n, t, track[21], psum[21];
void solve(int cur, int sum, vi& sel) {
	if (sum > n) return;
	if (cur == t) {
		if (sum > ansVal) {
			ansVal = sum;
			ans = sel;
		}
		return;
	}

	for (int next = cur; next < t; ++next)
		if (sum + track[next] <= n) {
			sel.push_back(track[next]);
			solve(next+1, sum+track[next], sel);
			sel.pop_back();
		}
	solve(t, sum, sel);
}

int main () {
	while (scanf("%d", &n) != EOF) {
		ans.clear();
		ansVal = 0;
		scanf("%d", &t);
		for (int i=0; i<t; ++i)
			scanf("%d", &track[i]);

		partial_sum(track, track+t, psum);
		vi sel;
		solve(0, 0, sel);

		for (int i=0; i<ans.size(); ++i)
			printf("%d ", ans[i]);
		printf("sum:%d\n",ansVal);
	}
	return 0;
}

