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

int testNum;

vector<int> PartialMatch (string &a) {
	int n = a.size(), begin = 1, matched =0;
	vector<int> ret(n, 0);

	while (begin + matched < n) {
		if (a[begin + matched] == a[matched]) {
			++matched;
			ret[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) ++ begin;
			else {
				begin += matched - ret[matched-1];
				matched = ret[matched-1];
			}
		}
	}
	return ret;
}

int KMP(string &cur, string &tar) {
	vector<int> p = PartialMatch (cur);
	int n = tar.size(), m = cur.size(), matched = 0;

	for (int i=0; i<n; ++i) {
		while (matched > 0 && tar[i] != cur[matched])
			matched = p[matched-1];
		if (tar[i] == cur[matched]) {
			++matched;
			if (matched == m)
				return i-m+1;
		}
	}


	return -1;
}


int main () {
	cin >> testNum;

	while (testNum--) {
		string cur;
		int N, ans = 0;
		cin >> N >> cur;

		for (int i=0; i<N; ++i) {
			string target;
			cin >> target;
			if (i%2 == 0) {
				string x = target+target;
				ans += KMP(cur, x);
			}
			else {
				string x = cur + cur;
				ans += KMP(target, x);
			}

			cur = target;
		}
		cout << ans << endl;


	}


	return 0;
}

