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
	int k, d[6], v[6], max12=0, max34=0;
	scanf("%d", &k);
	for (int i=0; i<6; ++i) {
		scanf("%d %d", &d[i], &v[i]);
		if (d[i] < 3) max12 = max(max12, v[i]);
		else max34 = max(max34, v[i]);
	}
	
	int i;
	bool flag = false;
	for (i=0; i<6; ++i) {
		if (d[i] < 3 && v[i] == max12) flag = true;
		else if (d[i] > 2 && v[i] == max34) flag = true;
		else if (flag) break;
	}

	printf("%d\n", k * (max12*max34 - v[(i+1)%6]*v[(i+2)%6]));

	return 0;
}


