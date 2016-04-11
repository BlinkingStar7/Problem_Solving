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

int pi[1000];
string H, N;
int main () {
	cin >> H >> N;

	for (int i=1; i<N.size(); ++i) {
		int cnt = 0;
		for (int j=0; i+j<N.size(); ++j)
			if (N[i+j] == N[j]) {
				++cnt;
				pi[(i+j)+1] = max(pi[(i+j)+1], cnt);
			}
			else
				break;
	}

	for (int i=0; i<N.size(); ++i)
		printf("%s => %s (%d)\n", N.substr(0, i+1).c_str(), N.substr(0, pi[i]).c_str(), pi[i]);

	puts("");
	puts("");

	int matched = 0, pos = 0;
	pi[0] = -1;
	while(pos < H.size()) {
		while (matched >= 0 && H[pos] != N[matched]) matched = pi[matched];
		++pos; ++matched;
		if (matched == N.size()) {
			printf("found on %d\n", pos-matched);
			matched = pi[matched];
		}
	}
	
	return 0;
}


