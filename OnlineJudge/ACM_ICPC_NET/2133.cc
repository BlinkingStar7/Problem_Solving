#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int N, Memo[31];
int Solve (int n) {
	if (n==2) return 3;
	if (n==0) return 1;
	int &ret = Memo[n];
	if (ret != -1) return ret;

	ret = 0;

	for (int next=n-2; next >=0; next-=2)
		ret += Solve(next);
	ret *= 2;
	return ret += Solve(n-2);
}

int main() {
	cin >> N;
	memset(Memo, -1, sizeof(Memo));
	if (N%2 == 1) cout << 0 << endl;
	else cout << Solve(N) << endl;
	return 0;
}


