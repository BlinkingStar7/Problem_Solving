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

int n, k;

void combination(vector<bool>& selected, int start, int left) {
	if (left == 0) {
		for (int i=0; i<=n; ++i)
			if (selected[i])
				printf("%d ", i);
		printf("\n");
		return;
	}

	if (start == n+1) return;

	for (int cur=start; cur<=n; ++cur) {
		selected[cur] = true;
		combination(selected, cur+1, left-1);
		selected[cur] = false;
	}
}

int main () {
	cin >> n >> k;
	vector<bool> selected(n+1, false);

	combination(selected, 0, k);

	return 0;
}

