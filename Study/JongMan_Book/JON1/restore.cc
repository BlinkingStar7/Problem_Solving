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

const int MAX = 987654321;
int C, K, Memo[16][1<<16];
string Str[16];

int Add (int head, int next) {
	if (head == -1) return Str[next].size();
	
	int start = 0;

	while (start < Str[head].size()) {
		int length = min ((int)Str[head].size() - start, (int)Str[next].size());
		if (Str[head].substr(start, length) == Str[next].substr(0, length))
			return max (0, (int)Str[next].size() - ((int)Str[head].size() - start));
		++start;
	}


	return Str[next].size();
}


int Solve (int head, int chk) {
	if (chk == (1 << K) -1) return 0;

	int &ret = Memo[head+1][chk];
	if (ret != 0) return ret;

	ret = MAX;

	for (int next=0; next<K; ++next) {
		if ((1<<next & chk) == 0) {
			int add = Add(head, next);
			if (add == 0) ret = min (ret, Solve(head, chk | 1<<next));
			else ret = min (ret, add + Solve (next, chk | 1<<next));
		}
	}
	return ret;
}

int main () {
	cin >> C;

	while (C--) {
		cin >> K;
		for (int i=0; i<K; ++i)
			cin >> Str[i];
		memset (Memo, 0, sizeof(Memo));
		cout << Solve (-1, 0) << endl; 

	}


	return 0;
}

