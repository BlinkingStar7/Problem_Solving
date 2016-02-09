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

int testNum, N, A[50001];

struct FW {
	vector<int> tree;
	FW (int n) : tree(n+1) {}
	int sum (int pos) {
		++pos;
		int ret = 0;
		while (pos > 0) {
			ret += tree[pos];
			pos &= (pos-1);
		}
		return ret;
	}
	void update (int pos, int val) {
		++pos;
		while (pos < tree.size()) {
			tree[pos] += val;
			pos += (pos&-pos);
		}
	}
};

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;
		FW f(1000*1000);
		int ans = 0;
		for (int i=0; i<N; ++i) {
			scanf("%d", A+i);
			f.update(A[i], 1);
			ans += f.sum(1000*1000-1) - f.sum(A[i]);
		}

		cout << ans << endl;

	}


	return 0;
}

