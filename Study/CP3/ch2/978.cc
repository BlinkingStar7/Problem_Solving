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
	for (int test=0; test<t; ++test) {
		int battle, sg, sb;
		scanf("%d%d%d", &battle, &sg, &sb);
		vector<int> green(sg), blue(sb);

		for (int i=0; i<sg; ++i)
			scanf("%d", &green[i]);
		for (int i=0; i<sb; ++i)
			scanf("%d", &blue[i]);
		priority_queue<int, vector<int>, less<int> > g(green.begin(),green.end()), b(blue.begin(),blue.end());
		
		while (1) {
			green.clear(); blue.clear();
			int battleNum = 0;
			while (battleNum++ < battle) {
				if (g.size() == 0 || b.size() == 0) break;

				DPRINTF(("Battle %d : g(%d) vs b(%d)\n", battleNum, g.top(), b.top())); 

				int remain = g.top() - b.top();
				if (remain > 0) green.push_back(remain);
				else if (remain < 0) blue.push_back(-remain);
				g.pop(); b.pop();
			}

			for (int i=0; i<green.size(); ++i)
				g.push(green[i]);
			for (int i=0; i<blue.size(); ++i)
				b.push(blue[i]);

			if (g.empty() || b.empty()) break;
		}

		if (test != 0) puts("");
		if (g.empty() && b.empty())
			printf("green and blue died\n");
		else if (b.empty()) {
			printf("green wins\n");
			for (priority_queue<int, vector<int>, less<int> >:: iterator i=g.begin(); i!=g.end(); ++i)
				printf("%d\n", *i);
		}
		else if (g.empty()) {
			printf("blue wins\n");
			for (priority_queue<int, vector<int>, less<int> >:: iterator i=b.bebin(); i!=b.end(); ++i)
				printf("%d\n", *i);
		}
	}
	return 0;
}

