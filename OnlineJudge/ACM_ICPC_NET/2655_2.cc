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

struct block {
	int s, h, w, index;
} B[101];
int N;
bool compare (const block&a, const block&b) {
	return a.s > b.s;
}

int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		scanf("%d%d%d",&B[i].s,&B[i].h,&B[i].w);
		B[i].index = i+1;
	}

	int D[101], ans[101];
	memset (D, 0, sizeof(D));
	sort (B, B+N, compare);
	for (int cur = N-1; cur >= 0; --cur) {
		int best = -1, Max = 0;
		for (int next = cur+1; next < N; ++next) {
			if (B[next].w < B[cur].w && D[next] > Max) {
				best = next;
				Max = D[next];
			}
		}
		D[cur] = B[cur].h + (best == -1 ? 0 : D[best]);
		ans[cur] = best;
	}

	vector<int> list;
	int cur = max_element(D, D+N)-D;

	while(cur != -1) {
		list.push_back(cur);
		cur = ans[cur];
	}

	cout << list.size() << endl;
	for (int i=list.size()-1; i>=0; --i)
		printf("%d\n", B[list[i]].index);

	return 0;
}

