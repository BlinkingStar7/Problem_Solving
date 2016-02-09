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

const int MOD = 1000000009;
long long D[2][7] = {1}, ans;
int main () {
	int n, k;
	scanf("%d%d", &n,&k);
	for (int i=1; i<=n; ++i) {
		int cur=i%2, bef=1-cur;
		D[cur][0] = ((k-1)*D[bef][0] + (k-2)*(D[bef][1] + D[bef][2] + D[bef][3] + D[bef][4] + D[bef][5] + D[bef][6]))%MOD;
		D[cur][1] = (D[bef][0] + D[bef][1] + D[bef][3] + D[bef][5] + D[bef][6])%MOD;
		D[cur][2] = D[bef][1];
		D[cur][3] = (D[bef][2] + D[bef][4])%MOD;
		D[cur][4] = D[bef][3];
		D[cur][5] = D[bef][2];
		D[cur][6] = D[bef][5];
	}

	for (int i=0; i<7; ++i) 
		ans = (ans + D[n%2][i])%MOD;
	printf("%lld\n", ans);
	return 0;
}


