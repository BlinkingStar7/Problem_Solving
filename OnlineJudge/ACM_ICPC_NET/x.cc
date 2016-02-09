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

struct President {
	int num, total, vote[4];
	President () {}
	President (int n) : num(n), total(0) {
		for (int i=0; i<4; ++i)
			vote[i] = 0;
	}

	void calcVote () {
		for (int i=3; i>=1; --i)
			total += i*vote[i];
	}

	bool operator () (President &a, President &b) {
		if (a.total != b.total) return a.total < b.total;
		for (int i=3; i>=1; --i)
			if (a.vote[i] != b.vote[i])
				return a.vote[i] < b.vote[i];
		return false;
	}
};

President P[4];
int N;

int main () {
	cin >> N;
	for (int i=0; i<3; ++i)
		P[i].num = i+1;

	for (int i=0; i<N; ++i) {
		for (int p=0; p<3; ++p) {
			int v;
			scanf("%d", &v);
			++P[p].vote[v];
		}
	}
	for (int i=0; i<3; ++i)
		P[i].calcVote();


	if (!President(P[0], P[1]) && !President(P[1], P[0])) {
		cout << 0 << " " << P[0].total << endl;
	}
	else {
		cout << P[0].num << " " << P[0].total << endl;
	}
	return 0;
}

