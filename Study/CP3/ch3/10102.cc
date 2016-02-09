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

int m;
int main () {
	while (scanf("%d", &m) != EOF) {
		vpii three, one;
		for (int i=0; i<m; ++i)
			for (int j=0; j<m; ++j) {
				int t;
				scanf("%1d", &t);
				if (t == 1) one.push_back(make_pair(i, j));
				else if (t == 3) three.push_back(make_pair(i,j));
			}
		
		int ans=0;
		for (int i=0; i<one.size(); ++i) {
			int cand = INF;
			for (int j=0; j<three.size(); ++j) {
				int d = abs(three[j].first - one[i].first) + abs(three[j].second - one[i].second);
				cand = min(d, cand);
			}
			ans = max(cand, ans);
		}
		printf("%d\n",ans);

	}
			
	return 0;
}

