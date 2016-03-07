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

int n;
char a[11];

void solve(int start, char toFind, int step) {
	int num = start, ans[11];
	for (int i=0; i<=n; ++i) {
		int len = 0;
		for (int j=i; j<n; ++j, ++len)
			if (a[j] == toFind) break;
		
		for (int j=len; j>=0; --j) {
			ans[i+j] = num;
			num += step;
		}
		i += len;
	}
	for (int i=0; i<=n; ++i)
		printf("%d", ans[i]);
	puts("");
}		

int main () {
	scanf("%d", &n); getchar();
	for (int i=0; i<n; ++i) scanf("%c%*c", a+i);

	solve(9, '>', -1);
	solve(0, '<', 1);

	return 0;
}


