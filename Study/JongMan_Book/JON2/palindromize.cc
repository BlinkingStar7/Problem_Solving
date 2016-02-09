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
string H, N;

int PartialMatch() {
	int n = N.size(), begin = 0, matched = 0;
	vector<int> p(n, 0);

	while (begin + matched < n) {
		if (H[begin + matched] == N[matched]) {
			++matched;
			p[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - p[matched-1];
				matched = p[matched-1];
			}
		}
	}
	return p[n-1];
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> H;
		N = H;
		reverse(N.begin(), N.end());
		if (N == H) cout << N.size() << endl;
		else 
			cout << 2*N.size() - PartialMatch() << endl;
	}


	return 0;
}

