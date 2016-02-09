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

int N;
struct block {
	int s, h, w, index;
} B[101];
bool compare (const block& a, const block& b) {
	return a.s != b.s ? a.s>b.s : a.w>b.w;
}
int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		scanf("%d%d%d", &B[i].s, &B[i].h, &B[i].w);
		B[i].index = i+1;
	}

	sort(B, B+N, compare);

	int D[101];

	for (int cur=N-1; cur >=0; --cur) {
		int cand = 0;
		for (int next=cur+1; next<N; ++next) {
			if (B[next].w < B[cur].w)
				cand = max(cand, D[next]);
		}
		D[cur] = B[cur].h + cand;
	}

	int start = max_element(D, D+N) - D;
	vector<int> ans;

	for (int i=ans; i<N; ++i) {



	return 0;
}

