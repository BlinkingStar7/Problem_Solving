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
	gets(str);
	n = strlen(str);

	for (int i=0; i<n; ++i) {
		sa[i] = i;
		g[0][i] = str[i];
	}

	for (int cnt=1, k=1; k<n; k<<=1, ++cnt) {
		cs(cnt-1, k);
		cs(cnt-1, 0);

		gg[sa[0]] = 1;
		for (int i=1; i<n; ++i)
			gg[sa[i]] = (g[sa[i]] == g[sa[i-1]] && g[sa[i]+k] == g[sa[i-1]+k]) ? 


	return 0;
}


