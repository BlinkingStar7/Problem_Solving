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

int testNum, N, M;
string D;

string BFS () {
	map<int, string> m;
	queue<int> q;
	q.push(-1);
	m[-1] = "";

	while (!q.empty()) {
		int here = q.front(); q.pop();
		string x = m[here];
		int len = x.size();

		for (int i=0; i<D.size(); ++i) {
			int toAdd = D[i] - '0';
			int there = ((here==-1?0:here)*10 + toAdd)%N;
			if (m.count(there) == 0) {
				if (len >= log10(N+M)) {
					if (len == log10(N+M) && (
					m[there] = x + string(1, D[i]);
				q.push(there);
			}
		}
	}
	return "IMPOSSIBLE";
}



int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> D >> N >> M;
		sort(D.begin(), D.end());
		cout << BFS() << endl;
	}


	return 0;
}

