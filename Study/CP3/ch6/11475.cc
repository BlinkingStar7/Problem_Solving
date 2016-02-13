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

string s;
int n, back[100001];

int main () {
	while (cin >> s) {
		n = s.size();
		int i=0, j=-1; back[0] = -1;
		while (i < n) {
			while (~j && s[n-i-1] != s[n-j-1]) j = back[j];
			++i, ++j;
			back[i] = j;
		}

		i=0, j=0;
		while (i < n) {
			while (~j && s[i] != s[n-j-1]) j = back[j];
			++i, ++j;
		}

		cout << s;
		for (int i=n-1-j; i>=0; --i) putchar(s[i]);
		puts("");
	}


	return 0;
}


