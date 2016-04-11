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

const int MAX = 131072;
int ss, tt;
char s[MAX], t[MAX];
int main () {
	while(1) {
		if (scanf("%s %s", s, t) == EOF) break;
		int ss = strlen(s), tt = strlen(t);

		int i=0, j=0;
		while (i<ss && j<tt) {
			if (s[i] == t[j++]) 
				++i;
		}
		printf("%s\n", i == ss ? "YES" : "NO");
	}

	return 0;
}


