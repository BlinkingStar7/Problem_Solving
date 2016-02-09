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

int testNum, K, N;
string S;

struct Comparator {
	const vector<int> &group;
	int t;
	Comparator (const vector<int> _group, int _t) : group(_group), t(_t) {}
	bool operator () (int a, int b) {
		if (group[a] != group[b]) return group[a]<group[b];
		return group[a+t] < group[b+t];
	}
};

vector<int> GetSuffixArray (string &s) {
	vector<int> suffix(N), group(N+1);
	for (int i=0; i<N; ++i) {
		suffix[i] = i;
		group[i] = s[i];
	}
	group[N] = -1;

	int t = 1;
	while (t < N) {
		puts("");
		for (int i=0; i<suffix.size(); ++i) {
			printf("group %d, realgroup %d\n",group[suffix[i]],group[i]);
			puts(S.c_str() + suffix[i]);
		}
		Comparator c(group, t);
		sort(suffix.begin(), suffix.end(), c);

		printf("\n After sorting\n");
		for (int i=0; i<suffix.size(); ++i) {
			printf("group %d, string : ",group[suffix[i]]);
			puts(S.c_str() + suffix[i]);
		}

		t*=2;
		if (t>=N) break;

		vector<int> newGroup(N+1);
		newGroup[suffix[0]] = 0;
		newGroup[N] = -1;

		for (int i=1; i<N; ++i) {
			if (c(suffix[i-1], suffix[i])) newGroup[suffix[i]] = newGroup[suffix[i-1]] + 1;
			else newGroup[suffix[i]] = newGroup[suffix[i-1]];
		}
		group = newGroup;
	}
	return suffix;
}

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> K >> S;
		N = S.size();

		vector<int> sfx = GetSuffixArray(S);
		for (int i=0; i<sfx.size(); ++i)
			cout << sfx[i] << endl;
	}


	return 0;
}

