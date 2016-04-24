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

int n, dir[100001], len[100001];
bool v[100001];

int main () {
	scanf("%d ", &n);
	for (int i=0; i<n; ++i) {
		char c;
		scanf("%c", &c);
		if (c == '>') dir[i] = 1;
		else dir[i] = 0;
	}
	for (int i=0; i<n; ++i)
		scanf("%d", len+i);

	queue<int> q;
	q.push(0);
	v[0] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int next = cur + (dir[cur] ? 1 : -1)*len[cur];
		if (next < 0 || next >= n) {
			printf("FINITE\n");
			break;
		}
		else if (v[next]) {
			printf("INFINITE\n");
			break;
		}
		else {
			v[next] = true;
			q.push(next);
		}
	}
	return 0;
}


