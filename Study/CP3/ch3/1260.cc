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

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, A[1001];
		cin >> n;
		int sum = 0;
		for (int i=0; i<n; ++i) {
			scanf("%d", A+i);
			for (int bef=0; bef<i; ++bef)
				if (A[bef] <= A[i]) ++sum;
		}
		printf("%d\n", sum);
	}

	return 0;
}


