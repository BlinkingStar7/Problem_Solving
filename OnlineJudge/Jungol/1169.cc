#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int N, M;

void dfs1 (int n, vector<int> &x) {
	if (n == 0) {
		for (int i=0; i<x.size(); ++i)
			printf("%d ", x[i]);
		puts("");
		return;
	}
	for (int i=1; i<=6; ++i) {
		x.push_back(i);
		dfs1 (n-1, x);
		x.pop_back();
	}
}

void dfs2 (int n, int l, vector<int> &x) {
	if (n == 0) {
		for (int i=0; i<x.size(); ++i)
			printf("%d ", x[i]);
		puts("");
		return;
	}
	for (int i=l; i<=6; ++i) {
		x.push_back(i);
		dfs2 (n-1, i, x);
		x.pop_back();
	}
}

void dfs3 (int n, vector<int> &x) {
	if (n == 0) {
		for (int i=0; i<x.size(); ++i)
			printf("%d ", x[i]);
		puts("");
		return;
	}
	for (int i=1; i<=6; ++i) {
		bool flag = true;
		for (int j=0; j<x.size(); ++j) {
			if (x[j] == i) {
				flag = false;
				break;
			}
		}
		if (flag) {
			x.push_back(i);
			dfs3 (n-1, x);
			x.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;
	vector<int> x;
	if (M == 1) dfs1 (N, x);
	else if (M == 2) dfs2 (N, 1, x);
	else dfs3 (N, x);
	return 0;
}


