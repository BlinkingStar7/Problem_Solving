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
#include <numeric>
using namespace std;

vector<int> PartialMatch(string &N) {
	int n = N.size(), begin = 1, matched = 0;
	vector<int> ret(n);
	
	while(begin + matched < n) {
		if (N[begin + matched ] == N[matched]) {
			++matched;
			ret[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - ret[matched-1];
				matched = ret[matched-1];
			}
		}
	}
	return ret;
}

int KMP (string H, string &N) {
	int n = H.size(), m = N.size(), matched = 0;
	vector<int> p = PartialMatch(N);

	for (int i=0; i<n; ++i) {
		while (matched > 0 && H[i] != N[matched])
			matched = p[matched-1];
		if (H[i] == N[matched]) {
			++matched;
			if (i == m - 1) return m-matched;
		}
	}
	return -1;
}

int main () {
	string s, rev;
	cin >> s;
	rev = s;
	reverse(rev.begin(), rev.end());

	cout << s.size() + KMP(s+s, rev) << endl;


	return 0;
}

