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
	int len, dot[3][2];
	scanf("%d", &len); len*=2;
	for (int i=0; i<3; ++i) for (int j=0; j<2; ++j) {
		scanf("%d", &dot[i][j]);
		dot[i][j] *= 2;
	}

	for (int i=0; i<3; ++i) {
		if (dot[i][0] == dot[i][1]) continue;
		int mid = (dot[i][0] + dot[i][1]) / 2;
		for (int j=i+1; j<3; ++j)
			for (int k=0; k<2; ++k)
				dot[j][k] = abs (dot[j][k] - mid);
		len = max(mid, len - mid);
	}

	printf("%d.%d\n", len/2, 5*(len%2));
	return 0;
}


