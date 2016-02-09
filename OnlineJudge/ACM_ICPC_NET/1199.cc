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

int N, adj[1001][1001], Num[1001];
void euler(int here) {

	int next = -1, val = -1;
	for (int i=0; i<N; ++i) {
		while (adj[here][i] > 0) {
			--adj[here][i];
			--adj[i][here];
			euler(i);
		}
	}

	printf("%d ", here+1);
}


int main () {

	cin >> N;
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j) {
			scanf("%d", &adj[i][j]);
			Num[i] += adj[i][j];
		}

	for (int i=0; i<N; ++i)
		if (Num[i]%2 || Num[i] == 0) {
			printf("-1\n");
			return 0;
		}

	euler(0);
	
			
	return 0;
}

