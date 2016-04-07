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

int a[10000][10000];
int main () {
	for (int i=0; i<10000; ++i) for (int j=0; j<10000; ++j)
		a[i][j] = -2;
	printf("start\n");
	for (int i=0; i<10000; ++i) for (int j=0; j<10000; ++j)
		a[i][j] = -2;
	printf("end\n");
	memset(a, -1, sizeof(a));
	printf("end\n");
}


