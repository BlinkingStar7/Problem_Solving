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

string wild, word[101];
int C, N, D[101][101];

int Solve (int w, int c, int a) {
	if (c == word[a].size()) {
		for (int x=w; x<wild.size(); ++x)
			if (wild[x] != '*') return 0;
		return 1;
	}
	if (w == wild.size()) return 0;

	int &ret = D[w][c];
	if (ret != -1) return ret;

	ret = 0;

	if (wild[w] == '*') {
		for (int next = c; next <= word[a].size(); ++next)
			ret = ret || Solve (w+1, next, a);
	}
	else if (wild[w] == '?') ret = Solve(w+1, c+1, a);
	else ret = (wild[w] == word[a][c]) ? Solve(w+1, c+1, a) : 0;
	return ret;
}
int main () {
	cin >> C;
	
	while (C--) {
		cin >> wild;
		cin >> N;
		for (int i=0; i<N; ++i)
			cin >> word[i];
		
		sort (word, word+N);

		for (int i=0; i<N; ++i) {
			memset(D, -1, sizeof(D));
			if (Solve(0, 0, i)) cout << word[i] << endl;
		}
		
	}
	return 0;
}

