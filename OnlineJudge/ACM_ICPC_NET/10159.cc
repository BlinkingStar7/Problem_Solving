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

int N, M, adj[101][101], num[101];
int main () {
	cin >> N >> M;
	for (int i=0; i<M; ++i) {
		int a, b;
		scanf("%d%d",&a,&b);
		adj[a][b] = 1;
	}
	

	return 0;
}

