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
	int n, s[101] = {0}, m, g, num;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", s+i);
	scanf("%d", &m);
	for (int i=0; i<m; ++i) {
		scanf("%d%d", &g, &num);
		if (g == 1) 
			for (int j=num; j<=n; j+=num)
				s[j] = 1 - s[j];
		else {
			int l=num-1, r=num+1;
			s[num] = 1 - s[num];
			while (1) {
				if (l==0 || r==n+1 || s[l] != s[r]) break;
				s[l] = s[r] = 1 - s[l];
				--l, ++r;
			}
		}

	}

		for (int i=1; i<=n; ++i)
			printf("%d%c", s[i], i == n || i%20 == 0 ? '\n' : ' ');

	return 0;
}


