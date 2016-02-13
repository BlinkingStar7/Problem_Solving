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
	scanf("%d", &t);
	while (t--) {
		int k, w, back[101]; back[0] = -1;
		char s[101][101];
		scanf("%d%d", &k, &w);
		scanf(" %s", s[0]);
		int ans = k;
		for (int word=1; word<w; ++word) {
			scanf(" %s", s[word]);
			int i=0, j=-1;
			while (i < k) {
				while (~j && s[word][i] != s[word][j]) j = back[j];
				++i, ++j;
				back[i] = j;
			}
			i=0, j=0;
			while (i < k) {
				while (~j && s[word-1][i] != s[word][j]) j = back[j];
				++i, ++j;
			}
			ans += (k-j);
		}
		printf("%d\n", ans);
	}

	return 0;
}


