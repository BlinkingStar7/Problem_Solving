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

int N, D[101];
pair <int, int> Wire[101];

int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		Wire[i] = make_pair(a, b);
	}
	sort(Wire, Wire+N);

	int ans = 1;
	D[N-1] = 1;
	for (int i=N-2; i>=0; --i) {
		int cur = Wire[i].second, cand = 0;
		for (int j=i+1; j<N; ++j) {
			if (Wire[j].second > cur)
				cand = max (cand, D[j]);
		}
		D[i] = 1 + cand;
		ans = max (ans, D[i]);
	}

	cout << N-ans << endl;
	return 0;
}

