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

#define MAX 100001

string s, t;
int back[MAX], slen, tlen;

void pp() {
	int i=0, j=-1; back[0] = -1;
	while (i < tlen) {
		while (j>=0 && t[i] != t[j]) j = back[j];
		++i, ++j;
		back[i] = j;
	}
}

int kmp() {
	int i=0, j=0;
	pp();
	while (i < slen) {
		while (j>=0 && s[i] != t[j]) j = back[j];
		++i, ++j;
		if (i == tlen) return i + (tlen - j);
	}
	return -1;
}

int main () {
	int n;
	scanf("%d", &n);
	while (n--) {
		cin >> s;
		t = s; reverse(t.begin(), t.end());
		s += s;
		slen = s.size(), tlen = t.size();
		printf("%d\n", kmp());
	}
	return 0;
}


