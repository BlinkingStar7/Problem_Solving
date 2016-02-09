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

#define END 1000000
int main () {
	int n, m;
	while(scanf("%d%d",&n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		bitset<2*END+1> start, end;
		bool flag = true;
		for (int i=0; i<n; ++i) {
			int s, e;
			scanf("%d%d",&s,&e);
			if (start[s] || end[e]) flag = false;
			start.set(s); end.set(e);
		}
		for (int i=0; i<m; ++i) {
			int s, e, g;
			scanf("%d%d%d", &s, &e, &g);

			while (s <= END) {
				if (start[s] || end[e]) flag = false;
				start.set(s); end.set(e);
				s += g; e += g;
			}
		}

		bool doing = false;
		for (int t=0; t<=END && flag; ++t) {
			if (doing) {
				if (end[t]) doing = false;
				if (start[t]) {
					if (doing) {
						flag = false; break;
					}
					else doing = true;
				}
			}
			else {
				if (end[t]) {
					flag = false; break;
				}
				if (start[t]) doing = true;
			}
		}
		if (flag) printf("NO CONFLICT\n");	
		else printf("CONFLICT\n");
	}

	return 0;
}

