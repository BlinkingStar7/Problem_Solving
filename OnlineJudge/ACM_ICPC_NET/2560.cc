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

int B[1000001];
const int MOD = 1000;
int main () {
	int a,b,d,N;
	scanf("%d%d%d%d", &a,&b,&d,&N);
	B[0] = 1;

	for (int day=1; day<=N; ++day) {
		if (day<a) B[day] = 0;
		else if (day<=(b-1)) B[day] = ((day == 1 ? 0 : B[day-1]) + B[day-a])%MOD;
		else B[day] = (B[day-1] + B[day-a] - B[day-b])%MOD;
	}
	
	
	for (int day=1; day<=N; ++day)
		B[day] = (B[day-1]+B[day])%MOD;

	printf("%d\n", (MOD + B[N] - (N >= d ? B[N-d] : 0))%MOD);
	return 0;
}


