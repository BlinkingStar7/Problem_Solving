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

int f, s, g, u, d, v[1000001];
int main () {
	scanf("%d%d%d%d%d", &f,&s,&g,&u,&d);

	memset(v, -1, sizeof(v));
	queue<int> q;
	q.push(s);
	v[s] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == g) {
			printf("%d\n", v[cur]);
			return 0;
		}

		int next = cur + u;
		if (next <= f && v[next] == -1) {
			v[next] = v[cur] + 1;
			q.push(next);
		}
		next = cur - d;
		if (next > 0 && v[next] == -1) {
			v[next] = v[cur] + 1;
			q.push(next);
		}
	}

	printf("use the stairs\n");	
	return 0;
}


