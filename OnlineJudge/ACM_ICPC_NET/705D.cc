#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 5005;
const ll INF = 1e15;
int N, S, E;
ll X[MAX], A[MAX], B[MAX], C[MAX], D[MAX], memo[MAX][MAX];

ll Solve (int cur, int in, int out) {
	if (cur == N) return in == 0 && out == 0 ? 0 : INF;

	if (cur != 0 && in == 0 && out == 0) return INF;

	ll &ret = memo[cur][in];
	ll dist = (in+out)*(cur == 0 ? 0 : X[cur] - X[cur-1]);
	if (ret != -1) return ret;

	ret = INF;
	if (cur == S) {
		if (in > 0) ret = min(ret, C[cur] + Solve(cur+1, in-1, out));
		ret = min(ret, D[cur] + Solve(cur+1, in, out+1)); 
	}
	else if (cur == E) {
		if (out > 0) ret = min(ret, A[cur] + Solve(cur+1, in, out - 1));
		ret = min(ret, B[cur] + Solve(cur+1, in+1, out));
	}
	else {
		if (out > 0 && in > 0) ret = min(ret, A[cur] + C[cur] + Solve(cur+1, in-1, out - 1));
		if (out > 0) ret = min(ret, A[cur] + D[cur] + Solve(cur+1, in, out));
		if (in > 0) ret = min(ret, B[cur] + C[cur] + Solve(cur+1, in, out));
		ret = min(ret, B[cur] + D[cur] + Solve(cur+1, in+1, out+1));
	}

	return ret += dist;
}

int main() {
	scanf("%d%d%d", &N, &S, &E);
	--S, --E;
	for (int i=0; i<N; ++i) scanf("%lld", X+i);
	for (int i=0; i<N; ++i) scanf("%lld", A+i);
	for (int i=0; i<N; ++i) scanf("%lld", B+i);
	for (int i=0; i<N; ++i) scanf("%lld", C+i);
	for (int i=0; i<N; ++i) scanf("%lld", D+i);
/*
	for (int i=0; i<N; ++i) {
		A[i] += X[i];
		B[i] -= X[i];
		C[i] += X[i];
		D[i] -= X[i];
	}
*/
	memset(memo, -1, sizeof(memo));
	printf("%lld\n", Solve(0, 0, 0));

	return 0;
}

