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

int N, A[2001], lis[2001], lds[2001];

int main () {
	int n;
	cin >> n;
	while (n--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			scanf("%d", A+i);

		int ans = 0;

		for (int cur=N-1; cur>=0; --cur) {
			lis[cur] = lds[cur] = 1;
			for (int next = cur+1; next<N; ++next) 
				if (A[next] > A[cur]) lis[cur] = max(lis[cur], 1+lis[next]);
				else if (A[next] < A[cur]) lds[cur] = max(lds[cur], 1+lds[next]);
			ans = max(ans, lis[cur] + lds[cur] - 1);
		}
		printf("%d\n", ans);
	}

	return 0;
}


