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

int N, A[1000002];
int main () {
	cin >> N;
	int ans = 0;
	for (int i=0; i<N; ++i) {
		int t;
		scanf("%d", &t);
		if (A[t+1] == 0)
			A[t+1] = ++A[t];
		else ++A[t];
		ans = max(ans, A[t]);
	}
	cout << N - ans << endl;
	return 0;
}

