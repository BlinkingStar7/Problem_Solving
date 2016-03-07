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
	int a, b, mod[98] = {0};
	scanf("%d%d",&a,&b);
	int cur = (a*a)%b, num = 1;
	while (1) {
		if (mod[cur]) { return printf("%d\n", num - mod[cur]), 0; }
		mod[cur] = num++;
		cur = (cur*a)%b;
	}


	return 0;
}


