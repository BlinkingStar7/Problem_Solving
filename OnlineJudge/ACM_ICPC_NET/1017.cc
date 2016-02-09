#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
using namespace std;

int testNum, N, A[51], B[51], chk[51];
bool Prime[2001];

void Aristo() {
	memset(Prime, true, sizeof(Prime));
	Prime[0] = Prime[1] = false;
	int sqrtn = sqrt(2000);
	for (int i=2; i<=sqrtn; ++i) {
		if (Prime[i]) {
			for (int j=i*i; j<=2000; j+=i)
				Prime[j] = false;
		}
	}
}
	
int Solve (int n) {
	if (n == N) return 1;
	if (chk[n]) return Solve(n+1);

	int ret = 0;
	chk[n] = true;
	for (int next = n+1; next<N; ++next) {
		if (!chk[next] && Prime[A[n] + A[next]]) {
			chk[next] = true;
			if (Solve(n+1)) ret += 1;
			chk[next] = false;
		}
	}
	chk[n] = false;
	return ret;
}
		
int main () {
	Aristo();

	cin >> N;
	for (int i=0; i<N; ++i)
		cin >> A[i];

	int flag = 0;
	for (int start=1; start<N; ++start) {
		memset(chk, false, sizeof(chk));
		chk[0] = true;
		if (Prime[A[0] + A[start]]) {
			chk[start] = true;
			int ret = Solve(1);
			if (ret) {
				flag = 1;
				for (int k=0; k<ret; ++k)
					printf("%d ", A[start]);
			}
		}
	}

	if (!flag) printf("-1");
	cout << endl;

	return 0;
}

