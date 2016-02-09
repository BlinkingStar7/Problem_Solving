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

int main () {
	string s1, s2;
	cin >> s1 >> s2;
	string s = s1 + s2;

	int n = s.size(), begin = 1, matched = 0;
	vector<int> p(n, 0);
	while (begin + matched < n) {
		if (s[begin + matched] == s[matched]) {
			++matched;
			p[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - p[matched - 1];
				matched = p[matched - 1];
			}
		}
	}

	vector<int> ans(1, n);
	int cur = n-1;
	while (p[cur] != 0) {
		ans.push_back(p[cur]);
		cur = p[cur]-1;
	}

	for (int i=ans.size()-1; i>=0; --i)
		cout << ans[i] << " ";



	
	return 0;
}

