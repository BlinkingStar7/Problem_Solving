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

#define MAX 1234567
string S;
int b[MAX], n;
int main () {
	while (cin >> S) {
		if (S == ".") break;
		n = S.size();
		b[0] = -1;
		int i=0, j=-1;
		while (i < n) {
			while (~j && S[i] != S[j]) j = b[j];
			++i, ++j;
			b[i] = j;
		}

		int ans = n%(n-b[n]) ? 1 : n/(n-b[n]);
		printf("%d\n", ans);
	}
	return 0;
}


