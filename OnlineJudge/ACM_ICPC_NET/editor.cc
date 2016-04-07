#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

#define MAX 10001
int n, m, p[MAX], r[MAX], opp[MAX], s[MAX], con, t;

int f (int i) { return p[i] == i ? i : (p[i] = f(p[i])); }
int merge (int a, int b) {
	if (a == -1 && b == -1) return -1;
	if (a == -1) return b;
	if (b == -1) return a;
	if (r[a] > r[b]) swap(a, b);
	p[a] = b;
	s[b] += s[a];
	if (r[a] == r[b]) r[b]++;
	return b;
}

int main () {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; ++i) {
			p[i] = i;
			s[i] = 1;
			r[i] = 0;
			opp[i] = -1;
		}

		bool ans = true;
		for (int i=0; i<m; ++i) {
			char input[10];
			int a, b;
			scanf("%s%d%d", input, &a, &b);
			a = f(a), b = f(b);
			if (!ans) continue;

			if (input[0] == 'A') {
				if (a == b) continue;
				if (opp[a] == b) { ans = false, con = i+1; continue; }

				int aa = merge(a, b);
				int bb = merge(opp[a], opp[b]);

				opp[aa] = bb;
				if (bb != -1) opp[bb] = aa;
			}
			else {
				if (a == b) { ans = false, con = i+1; continue; }
				if (opp[a] == b) continue;

				int aa = merge(a, opp[b]);
				int bb = merge(b, opp[a]);

				opp[aa] = bb;
				opp[bb] = aa;
			}
		}

		int num = 0;
		bool v[MAX]; memset(v, false, sizeof(v));
		for (int i=0; i<n; ++i) {
			int cur = f(i);
			if (!v[cur]) {
				v[cur] = true;
				if (opp[cur] != -1) v[opp[cur]] = true;
				num += max(s[cur], s[opp[cur]]);
			}
		}

		if (ans) printf("MAX PARTY SIZE IS %d\n", num);
		else printf("CONTRADICTION AT %d\n", con);
	}
	return 0;
}


