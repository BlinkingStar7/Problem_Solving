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

const long long MOD = 1000000007;
long long Factorial[100001];
int testNum, N, M, num[1000001], Profit[100001], Deadline[100001];
pair<int, int> Work[100001];

bool compare (const pair<int, int> &a,const pair<int, int> &b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

int main () {
	cin >> testNum;
	Factorial[0] = 1;
	for (int i=1; i<=100000; ++i)
		Factorial[i] = (Factorial[i-1]*i)%MOD;

	while (testNum--) {
		cin >> N >> M;
		memset(num, 0, sizeof(0));
		for (int i=0; i<N; ++i) {
			scanf("%d", Profit+i);
		num[Profit[i]]++;
		}

		for (int i=0; i<N; ++i) {
			scanf("%d", Deadline+i);
			Work[i] = make_pair(Profit[i], Deadline[i]);
		}

		sort(Work, Work+N, compare);
		
		long long cur=0, min=1;
		long long ans = 1;

		while (cur < N && min <= M) {
			int p = Work[cur].first, d = Work[cur].second;
			if (d >= min) {
				if (d > min) {
					ans = (ans*(d-min-p[num]+2))%MOD;
				}
				++min;
			}
			++cur;
		}
			
		printf("%lld\n", ans);
	}
	return 0;
}

