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

int N;
int main () {
	bool f = false;
	while (~scanf("%d ", &N)) {
		if (!f) f = true;
		else puts("");

		char *B = (char *)malloc((N+1)*sizeof(char));
		int *F = (int *)malloc((N+1)*sizeof(char));
		gets(B);

		char ch;
		for (int p=1, m=0; p<N; ++p) {
			while(m && B[m] != B[p]) m = F[m-1];
			F[p] = B[m] == B[p] ? ++m : m;
		}

		int m=0, cur=0;
		while (scanf("%c", &ch) && ch != '\n') {
			while (m && B[m] != ch) m = F[m-1];
			if (B[m] == ch) ++m;
			if (m == N) {
				printf("%d\n", cur-N+1);
				m == 0;
			}
			++cur;
		}
		free(B);
		free(F);
	}


	return 0;
}


