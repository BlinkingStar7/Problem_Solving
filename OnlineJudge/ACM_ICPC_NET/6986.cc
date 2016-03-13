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

void print(int a, int b) {
	int cur = a / b;
	printf("%d.",cur/1000);
	int cc = cur % 1000;
	int q = cc / 10;
	if (cc % 10 > 4) q+=1;
	printf("%02d\n", q);
}
int main () {
	int n, k, a[100001];
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; ++i) {
		int x,y;
		scanf("%d.%d", &x, &y);
		a[i] = (10*x+y)*100;
	}

	sort(a, a+n);

	int sum = 0;
	for (int i=k; i<n-k; ++i) sum += a[i];

	print(sum, n-2*k);
	print(sum+k*a[k]+k*a[n-k-1], n);
	return 0;
}


