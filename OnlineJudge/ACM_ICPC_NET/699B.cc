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

int N, M, num, R[1005], C[1005];
char A[1005][1005];

int main () {
	scanf("%d%d", &N, &M);
	
	for (int i=0; i<N; ++i)
		scanf("%s", &A[i][0]);

	for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
		if (A[i][j] == '*') {
			++R[i];
			++C[j];
			num++;
		}
	}

	for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
		int temp = R[i] + C[j] - (A[i][j] == '*' ? 1 : 0);
		if (temp == num) {
			printf("YES\n%d %d\n", i+1, j+1);
			return 0;
		}
	}
	
	printf("NO\n");

	return 0;
}


