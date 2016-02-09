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
#define MAX_N 100000
int main () {
	int A[MAX_N], B[MAX_N], num[MAX_N], size = 0, t, cnt = 0;
	while (scanf("%d", &t) != EOF) {
		int index = lower_bound(A, A+size, t) - A;
		A[index] = t;
		B[cnt] = t;
		num[cnt++] = index;
		if (index == size) ++size;
	}

	printf("%d\n-\n", size);
	vi ans(size);
	for (int i=cnt-1; i>=0; --i) 
		if (num[i] == size-1) {
			ans[size-1] = B[i];
			--size;
		}
	for (int i=0; i<ans.size(); ++i)
		printf("%d\n", ans[i]);

	return 0;
}


