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

int a, b, v[100001];

int main () {
	scanf("%d%d",&a,&b);
	memset(v, -1, sizeof(v));

	queue<int> q; q.push(a);
	v[a] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (cur == b) { 
			return printf("%d\n", v[cur]), 0;
		}
		if (cur>0 && v[cur-1] == -1) { v[cur-1] = v[cur]+1; q.push(cur-1); }
		if (cur<100000 && v[cur+1] == -1) { v[cur+1] = v[cur]+1; q.push(cur+1); }
		if (2*cur<100000 && v[2*cur] == -1) { v[2*cur] = v[cur]+1; q.push(cur*2); }
	}

	return 0;
}


