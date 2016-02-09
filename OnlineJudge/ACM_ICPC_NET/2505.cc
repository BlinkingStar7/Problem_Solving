#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <numeric>
using namespace std;

int N, A[10002], Ans[4][2];

void s(int a, int b) {
	while (a < b)
		swap (A[a++], A[b--]);
}

bool solved () {
	for (int i=1; i<=N; ++i) {
		if (A[i] != i) return false;
	}
	return true;
}

void Print(int cnt) {
	for (int i=0; i<cnt; ++i)
		printf("%d %d\n", Ans[i][0], Ans[i][1]);
	for (int i=0; i<2-cnt; ++i)
		printf("%d %d\n", 1, 1);
}


int main () {
	cin >> N;
	for (int i=1; i<=N; ++i)
		scanf("%d", A+i);

	int cnt = 0;	
	for (int i=1; i<=N; ++i) {
		if (A[i] != i) {
			int j;
			for (j=i+1; j<=N; ++j)
				if (A[j] == i) break;
			if (j == N+1) break;
			s (i, j);
			Ans[cnt][0] = i;
			Ans[cnt++][1] = j;
		}
		if (cnt > 2) break;
	}

	if (cnt > 2) {
		while (cnt != 0) {
			--cnt;
			s(Ans[cnt][0], Ans[cnt][1]);
		}
	}
	else {
		Print(cnt);
		return 0;
	}

	for (int i=N; i>=1; --i) {
		if (A[i] != i) {
			int j;
			for (j=i-1; j>=1; --j)
				if (A[j] == i) break;
			s (j, i);
			Ans[cnt][0] = j;
			Ans[cnt++][1] = i;
		}
	}

	Print(cnt);
			
	return 0;
}

