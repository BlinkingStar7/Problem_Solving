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
int n, k, s[101], a[101][1001];
int main () {
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) {
		scanf("%d", &s[i]);
		for (int j=0; j<s[i]; ++j)
			scanf("%d", &a[i][j]);
	}

	for (int start=0; start+k<=s[0]; ++start) {
		bool ans = true;
		int f[1001] = {0};
		int m = 0;

		for (int i=start+1; i<s[0]; ++i) {
			while (m>0 && a[0][i] != a[0][start+m]) m = f[start+m-1];
			if (a[0][i] == a[0][start+m]) 
				f[i] = ++m;
		}

		for (int i=1; i<n; ++i) {
			int m = 0;
			bool flag = false;
			for (int j=0; j<s[i]; ++j) {
				while (m>0 && a[i][j] != a[0][start+m]) m = f[start+m-1];
				if (a[i][j] == a[0][start+m]) {
					if (++m == k) { flag = true; break;}
				}
			}

			if (flag) continue;

			m = 0;
			for (int j=s[i]-1; j>=0; --j) {
				while (m>0 && a[i][j] != a[0][start+m]) m = f[start+m-1];
				if (a[i][j] == a[0][start+m]) {
					if (++m == k) { flag = true; break; }
				}
			}

			if (!flag) { ans = false; break; }
		}
		if (ans) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
	return 0;
}


