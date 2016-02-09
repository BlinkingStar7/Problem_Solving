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
	int n[] = { 10, 9, 8, 8, 7, 6, 5, 4, 4, 3, 2, 1};
	for (int i=0; i<12; ++i) printf("%d ", n[i]);
	puts("");
	int a, b;
	scanf("%d%d", &a,&b);
	printf("lower_bound at %d\n", lower_bound(n, n+12, a, greater<int>()) - n);
	printf("upper_bound at %d\n", upper_bound(n, n+12, b, greater<int>()) - n);
	return 0;
}


