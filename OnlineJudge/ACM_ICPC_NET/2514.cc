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

int m, k, r[9], c[9], b[9][9];
int main () {
	scanf("%d%d", &m, &k);
	for (int i=0; i<8; ++i) for (int j=0; j<8; ++j) {
		scanf("%d", &b[i][j]);
		b[i][j] -= m;
		r[i] += b[i][j], c[j] += b[i][j];
	}

	for (int i=0; i<8; ++i) {
		for (int j=0; j<8; ++j) {
			int cur = r[i]+c[j]-b[i][j];
			putchar(' ');
			if(cur%2) {
				if (abs(cur)%4 == 3) putchar('+');
				else putchar('-');
			}
			else putchar('.');
		}
		putchar('\n');
	}

	return 0;
}


