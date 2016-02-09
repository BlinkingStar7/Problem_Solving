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

int n, w[2001], memo[201][201][201];
int solve(int cur, int front, int end) {
	if (cur == n) return 0;

	int &ret = memo[cur][front+1][end+1];
	if (ret != -1) return ret;

	ret = 0;

	if (front == -1) ret = 1+solve(cur+1, cur, cur);
	else if (w[cur] > w[front]) ret = 1+solve(cur+1, cur, end);
	else if (w[cur] < w[end]) ret = 1+solve(cur+1, front, cur);

	return ret = max(ret, solve(cur+1, front, end));
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i=0; i<n; ++i) scanf("%d", w+i);
		memset(memo, -1, sizeof(memo));

		printf("%d\n", solve(0, -1, -1));
	}

	return 0;
}


