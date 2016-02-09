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
	int testNum;
	scanf("%d",&testNum);
	while (testNum--) {
		int battle, sg, sb;
		scanf("%d%d%d", &battle, &sg, &sb);
		multiset<int, greater<int> > g, b;
		for (int i=0; i<sg; ++i) {
			int t;
			scanf("%d", &t);
			g.insert(t);
		}
		for (int i=0; i<sb; ++i) {
			int t;
			scanf("%d", &t);
			b.insert(t);
		}

		while(1) {
			vi green, blue;
			int cnt=0;
			while(cnt++ < battle) {
				if (g.empty() || b.empty()) break;
				DPRINTF(("battle %d : g(%d) vs b(%d)\n", cnt, *g.begin(), *b.begin()));
				int remain = *g.begin() - *b.begin();
				g.erase(g.begin()); b.erase(b.begin());
				if (remain > 0) green.push_back(remain);
				else if (remain < 0) blue.push_back(-remain);
			}

			for (int i=0; i<green.size(); ++i) g.insert(green[i]);
			for (int i=0; i<blue.size(); ++i) b.insert(blue[i]);

			if (g.empty() || b.empty()) break;
		}

		if (g.empty() && b.empty())
			printf("green and blue died\n");
		else if (g.empty()) {
			printf("blue wins\n");
			for (multiset<int>::iterator it=b.begin(); it != b.end(); ++it) printf("%d\n", *it);
		}
		else {
			printf("green wins\n");
			for (multiset<int>::iterator it=g.begin(); it != g.end(); ++it) printf("%d\n", *it);
		}
		if (testNum) puts("");
	}

	return 0;
}

