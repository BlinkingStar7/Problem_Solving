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

char s[101][10001];

int main () {
	int t; scanf("%d", &t);
	while (t--) {
		int word; scanf("%d", &word);
		scanf(" %s", s[0]);
		int n = strlen(s[0]), ans = 0;
		for (int w=1; w<=word; ++w) {
			scanf(" %s", s[w]);
			int back[10001], i=0, j=-1; back[0] = -1;
			int str = w%2 ? w : w-1, tar = w%2 ? w-1 : w;
			while (i < n) {
				while (~j && s[tar][i] != s[tar][j]) j = back[j];
				++i, ++j;
				back[i] = j;
			}

			i=0, j=0;
			while (i < 2*n) {
				while (~j && s[str][i%n] != s[tar][j]) j = back[j];
				++i, ++j;
				if (j == n) break;
			}
			ans += i-n;
		}

		printf("%d\n", ans);
	}
	return 0;
}


