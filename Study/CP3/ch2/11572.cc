#include <bits/stdc++.h>
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

int main () {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		queue<int> q;
		set<int> sel;
		int best=0;
		for (int i=0; i<n; ++i) {
			int flake;
			scanf("%d", &flake);
			if (sel.find(flake) == sel.end()) {
				sel.insert(flake);
				q.push(flake);
			}
			else {
				while (q.front() != flake) {
					sel.erase(sel.find(q.front()));
					q.pop();
				}
				q.pop();
				q.push(flake);
			}
			best = max(best, (int)q.size());
		}
		printf("%d\n", best);
	}
	return 0;
}

