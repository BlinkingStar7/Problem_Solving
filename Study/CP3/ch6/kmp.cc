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

vi pp(string& N) {
	int i=0, j=-1, m=N.size();
	vi b(m+1); b[0] = -1;
	cout << endl;
	while (i<=m) {
		while(j>=0 && N[i] != N[j]) j = b[j];
		++i, ++j;
		b[i] = j;
	}
	return b;
}

vi kmp(string& H, string& N) {
	vi b = pp(N), ret;
	for (int i=0; i<b.size(); ++i)
		printf("%d", b[i]);
	puts("");
	int i=0, j=0, n = H.size(), m = N.size();
	while (i < n) {
		while (j >=0 && H[i] != N[j]) j = b[j];
		++i, ++j;
		if (j == m) { ret.push_back(i-m); j = b[j]; }
	}
	return ret;
}

int main () {
	string H, N;
	cin >> H >> N;
	vi found = kmp(H, N);
	cout << N << "has been found in ";
	for (int i=0; i<found.size(); ++i)
		cout << found[i] << " ";
	
	return 0;
}


