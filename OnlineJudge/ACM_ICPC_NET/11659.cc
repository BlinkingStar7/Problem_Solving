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
typedef long long ll;
typedef unsigned long long ull;

int main () {
	int N, M, A[100001];
	cin >> N >> M;
	A[0] = 0;
	for (int i=1; i<=N; ++i) {
		scanf("%d", A+i);
		A[i] += A[i-1];
	}

	for (int i=0; i<M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", A[b] - A[a-1]);
	}

	return 0;
}


