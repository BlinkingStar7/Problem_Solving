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

int testNum, N;
map<vector<int>, int> toSort;

void precalc(int n) {
	vector<int> perm(n);
	for (int i=0; i<n; ++i) perm[i] = i;
	queue<vector<int> > q;
	q.push(perm);
	toSort[perm] = 0;

	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		int cost = toSort[here];
		for (int i=0; i<n; ++i) {
			for (int j=i+2; j<=n; ++j) {
				reverse(here.begin()+i, here.begin()+j);
				if (toSort.count(here) == 0) {
					q.push(here);
					toSort[here] = cost+1;
				}
				reverse(here.begin()+i, here.begin()+j);
			}
		}
	}			
}

int BFS (vector<int> &input) {
	int n = input.size();
	vector<int> fixed(n);
	for (int i=0; i<n; ++i) {
		int smaller=0;
		for (int j=0; j<n; ++j)
			if (input[j] < input[i])
				++smaller;
		fixed[i] = smaller;
	}
	return toSort[fixed];
}

				
int main () {
	cin >> testNum;
	for (int i=1; i<=8; ++i)
		precalc(i);

	while (testNum--) {
		cin >> N;
		vector<int> input;
		for (int i=0; i<N; ++i) {
			int t;
			scanf("%d", &t);
			input.push_back(t);
		}

		cout << BFS(input)<< endl;

	}
	return 0;
}

