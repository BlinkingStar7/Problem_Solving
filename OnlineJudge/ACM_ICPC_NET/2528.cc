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

int N, L, len[3001], d[3001], t;
int Pos (int i) {
	if (len[i] == L) return 0;
	int Dir= (d[i]+t/(L-len[i]))%2;
	return Dir ? L-len[i]-t%(L-len[i]) : t%(L-len[i]);
}

int main () {
	cin >> N >> L;
	for (int i=0; i<N; ++i)
		scanf("%d%d", len+i, d+i);

	for (int i=0; i<N-1; ++i) {
		while (min(Pos(i)+len[i], Pos(i+1)+len[i+1]) - max(Pos(i), Pos(i+1)) < 0)
			++t;
	}
	printf("%d\n", t);
	return 0;
}

