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
#include <numeric>
using namespace std;
#define SQR(x) ((x)*(x))
int testNum, N, X[101], Y[101], parent[101], height[101];
pair<int, int> RI[101];
bool leaf[101];

bool Include (int a, int b) {
	int i=RI[a].second, j=RI[b].second;
	int d2 = SQR(X[i] - X[j]) + SQR(Y[i] - Y[j]);
	return RI[a].first - RI[b].first > sqrt(d2);

}

int Distance (int a, int b) {
	if (height[a] > height[b]) return 1 + Distance(parent[a], b);
	else if (height[a] < height[b]) return Distance(b, a);
	else return a==b?0:2+Distance(parent[a], parent[b]);
}
int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N;
		for (int i=0; i<N; ++i) {
			int r;
			scanf("%d %d %d", X+i, Y+i, &r);
			RI[i] = make_pair(r, i);
		}
		sort(RI, RI+N, greater<pair<int, int> >());

		for (int i=1; i<N; ++i) {
			for (int j=i-1; j>=0; --j) {
				if (Include(j, i)) {
					parent[i] = j;
					height[i] = height[j] + 1;
					leaf[j] = false;
					leaf[i] = true;
					break;
				}
			}
		}

		int ans = 0;

		for (int i=0; i<N; ++i) {
			if (leaf[i]) {
				ans = max (ans, height[i]);
				for (int j=i+1; j<N; ++j)
					if (leaf[j]) 
						ans = max (ans, Distance(i, j));
			}
		}
		cout << ans << endl;
	}


	return 0;
}

