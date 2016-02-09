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

int N, memo1[2001], memo2[2001], A[2001];
int LDS(int cur) {
	int &ret = memo2[cur];
	if (ret != -1) return ret;

	ret = 1;

	for (int next = cur+1; next<N; ++next)
		if (A[next] < A[cur]) ret = max(ret, 1+LDS(next));
	return ret;
}
int LIS(int cur) {
	int &ret = memo1[cur];
	if (ret != -1) return ret;

	ret = 1;

	for (int next = cur+1; next<N; ++next)
		if (A[next] > A[cur]) ret = max(ret, 1+LIS(next));
	return ret;
}

int main () {
	int n;
	cin >> n;
	while (n--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			scanf("%d", A+i);

		int ans = 0;
		memset(memo1, -1, sizeof(memo1));
		memset(memo2, -1, sizeof(memo2));
		for (int i=0; i<N; ++i)
			ans = max(ans, LIS(i) + LDS(i) - 1);
		printf("%d\n", ans);
	}

	return 0;
}


