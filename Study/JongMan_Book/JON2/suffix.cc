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

struct Comparator {
	const vector<int>& group;
	int t;

	Comparator(const vector<int>& _group, int _t) : group(_group), t(_t) {}
	bool operator () (int a, int b) {
		if (group[a] != group[b]) return group[a] < group[b];
		else return group[a+t] < group[b+t];
	}
};

vector<int> GetSuffixArray (const string& s) {
	int t = 1, n = s.size();
	vector<int> group(n+1), suffix(n);
	for (int i=0; i<n; ++i) {
		suffix[i] = i;
		group[i] = s[i];
	}
	group[n] = -1;

	while (t<n) {
		Comparator c(group, t);
		sort(suffix.begin(), suffix.end(), c);

		t*=2;
		if (t>=n) break;

		vector<int> newGroup(n+1);
		newGroup[suffix[0]] = 0;
		newGroup[n] = -1;
		for (int i=1; i<n; ++i) {
			if (c(suffix[i-1], suffix[i])) newGroup[suffix[i]] = newGroup[suffix[i-1]]+1;
			else newGroup[suffix[i]] = newGroup[suffix[i-1]];
		}
		group = newGroup;
	}
	return suffix;
}

int main () {
	string s;
	cin >> s;

	vector<int> suffixArray = GetSuffixArray(s);

	for (int i=0; i<suffixArray.size(); ++i)
		puts(s.c_str() + suffixArray[i]);


	return 0;
}

