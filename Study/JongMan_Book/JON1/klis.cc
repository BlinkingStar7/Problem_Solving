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
using namespace std;

const long long MAX = 1LL << 32;
int Len[501],C, N, A[501];
long long K, Num[501];

int length(int n) {
	int &ret = Len[n+1];
	if (ret != 0) return ret;

	ret = 1;

	for (int next=n+1; next<N; ++next)
		if (n == -1 || A[next] > A[n])
			ret = max (ret, 1+length(next));

	return ret;
}

long long lisNum(int n) {
	long long &ret = Num[n+1];
	if (ret != 0) return ret;

	if (Len[n+1] == 1) return ret = 1;

	ret = 0;

	for (int next=n+1; next<N; ++next)
		if ((n == -1 || A[next] > A[n]) && Len[next+1] == Len[n+1] - 1) {
			ret = min<long long> (MAX, ret + lisNum(next));
		}
	return ret;
}

void Solve(int n, int k) {
	if (Len[n+1] == 1) {
		printf("\n");
		return;
	}
	

	vector<pair<int, int> > list;

	for (int next=n+1; next<N; ++next) {
		if ((n == -1 || A[next] > A[n]) && Len[next+1] == Len[n+1] -1) {
			pair<int, int> p(A[next], next);
			list.push_back(p);
		}
	}

	sort (list.begin(), list.end());

	for (int i=0; i<list.size(); ++i) {
		int next = list[i].second;
		if (k <= Num[next+1]) {
			printf("%d ", A[next]);
			return Solve(next, k);
		}
		else k -= Num[next+1];
	}
}

int main () {
	cin >> C;

	while (C--) {
		cin >> N >> K;
		for (int i=0; i<N; ++i)
			scanf("%d", A+i);

		memset (Len, 0, sizeof(Len));
		memset (Num, 0, sizeof(Num));

		cout << length(-1) -1 << endl;
		lisNum (-1);
		Solve (-1, K);
		


	}


	return 0;
}

