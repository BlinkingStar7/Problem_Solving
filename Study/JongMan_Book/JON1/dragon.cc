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
using namespace std;

const int  MAX = 1000000000 + 1;
const string expand_X = "X+YF", expand_Y = "FX-Y";
int C, N, P, L, Skip, Len[51];

char Solve(const string& c, int generation, int skip) {
	if (generation == 0) return c[skip];
	
	for (int i=0; i<c.size(); ++i) {
		if (c[i] == 'X' || c[i] == 'Y') {
			if (Len[generation] <= skip) skip-=Len[generation];
			else if (c[i] == 'X') return Solve (expand_X, generation-1, skip);
			else return Solve(expand_Y, generation-1, skip);
		}
		else if (skip > 0) --skip;
		else return c[i];
	}
	return '#';
}


int main () {
	cin >> C;

	Len[0] = 1;
	for (int k=1; k<=50; ++k)
		Len[k] = min (MAX, Len[k-1] * 2 + 2);

	while (C--) {
		cin >> N >> P >> L;
		for (int i=0; i<L; ++i)
			cout << Solve ("FX", N, P+i-1);
		cout << endl;

	}
	return 0;
}

