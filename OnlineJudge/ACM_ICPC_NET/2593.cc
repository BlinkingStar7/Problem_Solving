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

const int START = -2, END = -3;
int n, m, a, b, x[101], y[101], v[101];
vi adj[101];

inline bool canTake(int e, int f) {
	return f>=x[e] && (f-x[e])%y[e] == 0;
}

inline bool hasEdge(int e1, int e2) {
	for (int i=x[e1]; i<=n; i+=y[e1])
		if (canTake(e2, i)) return true;
	return false;
}


int main () {
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; ++i) 
		scanf("%d%d",x+i,y+i);
	scanf("%d%d",&a,&b);
	if (a == b) {
		printf("0\n");
		return 0;
	}

	for (int i=0; i<m; ++i) for (int j=i+1; j<m; ++j)
		if (hasEdge(i, j)) {
			adj[i].push_back(j);
			adj[j].push_back(i);
		}

	queue<int> q;
	memset(v, -1, sizeof(v));

	for (int i=0; i<m; ++i) {
		if (canTake(i, a)) {
			q.push(i);
			v[i] = START;
		}
		if (canTake(i, b)) {
			if (v[i] == START) {
				printf("1\n%d\n",i+1);
				return 0;
			}
			v[i] = END;
		}
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i=0; i<adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (v[next] == -1) {
				v[next] = cur;
				q.push(next);
			}
			else if (v[next] == END) {
				vi ans; ans.push_back(next);
				int t = cur;
				while (t != START) {
					ans.push_back(t);
					t = v[t];
				}
				printf("%d\n", ans.size());
				for (int j=ans.size()-1; j>=0; --j)
					printf("%d\n", ans[j]+1);
				return 0;
			}
		}
	}

	printf("-1\n");
	return 0;
}


