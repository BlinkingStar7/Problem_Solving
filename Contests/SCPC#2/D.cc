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

int testNum, N;
pair<int, int> P[100001];

bool compare (const pair<int, int> &a, const pair<int, int> &b) {
		if (a.first != b.first) return a.first > b.first;
		return a.second < b.second;
} 

int main () {
	cin >> testNum;

	for (int tn=1; tn<=testNum; ++tn) {
		cin >> N;
		for (int i=0; i<N; ++i)
			scanf("%d %d", &P[i].first, &P[i].second);

		sort(P, P+N, compare);
		
		vector<int> ans;

		for (int i=0; i<N; ++i) {
			vector<int>::iterator it = upper_bound(ans.begin(), ans.end(), P[i].second);
			if (it == ans.end()) ans.push_back(P[i].second);
			else *it = P[i].second;
		}

		printf("Case #%d\n", tn);
		printf("%d\n", (int)ans.size());
	}

	return 0;
}

