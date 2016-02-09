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

int n, sToi[10001], iTos[10001], num[10001], memo[10002];

int solve(int cur) {
	int &ret = memo[cur+1];
	if (ret != -1) return ret;

	ret = 1;
	for (int i=cur+1; i<n; ++i)
		if (cur == -1 || num[i] > num[cur]) ret = max(ret, 1+solve(i));
	return ret;
}

void recon(vi& ans, int cur) {
	ans.push_back(iTos[cur]);
	for (int i=cur+1; i<n; ++i)
		if (solve(i) == solve(cur)-1)
			return recon(ans, i);
}


int main () {
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		int t;
		scanf("%d", &t);
		sToi[t] = i;
		iTos[i] = t;
	}
	for (int i=0; i<n; ++i) {
		int t;
		scanf("%d", &t);
		num[sToi[t]] = i;
	}

	vi ans;
	memset(memo, -1, sizeof(memo));
	printf("%d\n", solve(-1)-1);
	recon(ans, -1);
	sort(ans.begin(), ans.end());
	for (int i=1; i<ans.size(); ++i)
		printf("%d ", ans[i]);
	return 0;
}


