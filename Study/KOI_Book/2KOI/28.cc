#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int N, D[21], S[21], A[21], Memo[21][21][21];

int canReach1(int f, int t) {
	return D[t] - D[f] <= S[f];
}

int canReach2(int f, int t) {
	return A[f] && (D[t] - D[f] <= S[t]);
}

int Solve(int a, int b, int p) {
	if (p == N-1)
		return canReach1(a, p) && canReach2(b, p) ? 1 : 0;

	int &ret = Memo[a][b][p];
	if (ret != -1) return ret;

	ret = Solve(a, b, p+1);
	if (canReach1(a, p)) ret += Solve(p, b, p+1);
	if (canReach2(b, p)) ret += Solve(a, p, p+1);

	return ret;
}

int main () {
	memset(Memo, 0, sizeof(Memo));

	cin >> N;
	for (int i=0; i<N; ++i)
		cin >> D[i] >> S[i] >> A[i];

	for (int p=1; p<N-1; ++p) {
		for (int a=0; a<20 && a<=p; ++a) {
			for (int b=0; b<20 && b<=p; ++b) {
				if (a==b) break;							
				if (a!=p && b!=p) Memo[a][b][p] = Memo[a][b][p-1];
				else if (a==p) {
					for (int x=0; x<a; ++x) 
						if (x!=b && canReach1(x, a)) Memo[a][b][p] += Memo[x][b][p-1];
				}
				else if (b==p) {
					for (int x=0; x<b; ++x)
						if (x!=a && canReach2(x, a)) Memo[a][b][p] += Memo[a][x][p-1];
				}
			}
		}
	}

	int ans = 0;
	for (int a=0; a<N-1; ++a)
		for (int b=0; b<N-1; ++b)
			if (a!=b && canReach1(a, N-1) && canReach2(b, N-1))
				ans += Memo[a][b][N-2];

	cout << ans << endl;
	return 0;
}

