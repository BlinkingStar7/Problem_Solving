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
	string H, N;
	cin >> H >> N;
	int pos = 0, num = 0;
	for (int i=0; i<H.size(); ++i) {
		if (H[i] == N[pos]) {
			++pos;
			if (pos == N.size()) {
				++num;
				pos = 0;
			}
		}
		else pos = 0;
	}

	printf("%d\n", num);
	return 0;
}


