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

const int MOD = 1000000007;
int testNum, N, M, Profit[11], Deadline[11], Factorial[11];

int main () {
	cin >> testNum;
	Factorial[0] = 1;
	for (int i=1; i<11; ++i)
		Factorial[i] = Factorial[i-1]*i;
	while (testNum--) {
		cin >> N >> M;
		for (int i=0; i<N; ++i)
			scanf("%d", Profit+i);
		for (int i=0; i<N; ++i)
			scanf("%d", Deadline+i);

		sort(Profit, Profit+N);

		vector<pair<int, int> > ans;
		for (int i=0; i<M; ++i) {
			int found = -1, cur = Profit[N-1-i];
			for (int j=0; j<ans.size(); ++j)
				if (ans[j].first == cur) {
					found = j;
					break;
				}
			if (found == -1) 
				ans.push_back(make_pair(cur, 1));
			else
				ans[found].second++;
		}

		int num = Factorial[M];
		for (int i=0; i<ans.size(); ++i)
			num /= Factorial[ans[i].second];

		printf("%d\n", num);
	}
	return 0;
}

