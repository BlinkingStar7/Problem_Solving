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

struct DisSet {
	vector<int> parent, size, rank, opp;
	DisSet(int n) : parent(n), size(n, 1), rank(n), opp(n, -1) {
		for (int i=0; i<n; ++i)
			parent[i] = i;
	}
	int getParent (int a) {
		if (parent[a] == a) return a;
		else return parent[a] = getParent(parent[a]);
	}
	int Union (int a, int b) {
		if (a == -1 || b == -1) return max(a, b);
		a = getParent(a), b= getParent(b);
		if (a == b) return a;
		if (rank[a] > rank[b]) swap(a, b);
		if (rank[a] == rank[b]) ++rank[b];
		parent[a] = b;
		size[b] += size[a];
		return b;
	}

	bool ACK (int a, int b) {
		a = getParent(a), b = getParent(b);
		if (opp[a] == b) return false;
		int x = Union(a, b), y = Union(opp[a], opp[b]);
		opp[x] = y;
		if (y != -1) opp[y] = x;
		return true;

	}

	bool DIS (int a, int b) {
		a = getParent(a), b = getParent(b);
		if (a == b) return false;
		int x = Union(a, opp[b]), y = Union(b, opp[a]);
		opp[x] = y, opp[y] = x;
		return true;
	}
};
		
int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> M;
		DisSet dset(N);
		int contradic = -1;
		for (int i=0; i<M; ++i) {
			string c;
			int a, b;
			cin >> c;
			scanf("%d %d", &a, &b);
			if (contradic != -1) continue;
			if (c == "ACK" && !dset.ACK(a, b)) contradic = i;
			else if (c == "DIS" && !dset.DIS(a, b)) contradic = i;
		}

		if (contradic != -1)
			printf("CONTRADICTION AT %d\n", contradic + 1);
		else {
			int num=0;
			for (int i=0; i<N; ++i) {
				if (dset.opp[i] == i) {
					int e = dset.opp[i];
					if (e > i) continue;
					int mySize = dset.size[i];
					int eSize = e == -1 ? 0 : dset.size[e];
					num += max(mySize, eSize);
				}

			}
			printf("MAX PARTY SIZE IS %d\n", num);
		}
				
				




	}


	return 0;
}

