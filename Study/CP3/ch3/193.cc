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

int main () {
	int m;
	cin >> m;
	for (int cnt=0; cnt<m; ++cnt) {
		scanf("%d%d",&n,&k);
		memset(adj, false, sizeof(adj));

		for (int i=0; i<k; ++i) {
			int a, b;
			scanf("%d%d",&a,&b);
			adj[a][b] = adj[b][a] = true;
		}

		dfs(1);
	return 0;
}

