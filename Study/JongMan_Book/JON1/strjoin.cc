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

int C, N, A[101];

int main () {
	cin >> C;

	while (C--) {
		cin >> N;
		for (int i=0; i<N; ++i)
			scanf("%d", A+i);

		int cost = 0;
		multiset<int> set (A, A+N);

		while (set.size() > 1) {
			int t = *set.begin() + *(++set.begin());
			cost += t;
			set.erase(set.begin());
			set.erase(set.begin());
			set.insert(t);
		}

		cout << cost << endl;
	}

	return 0;
}

