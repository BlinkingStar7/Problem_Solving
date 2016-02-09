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

int N, M, X[100001], Y[100001];
int main () {
	cin >> N >> M;
	for (int i=0; i<M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		++X[x], ++Y[y];
	}

	int cntx = 0, cnty=0, sum = 0;

	for (int i=1; i<=N; ++i) {
		while(X[i]) {
			if (cntx < M/2) sum -= i;
			else if (cntx > M/2) sum += i;
			--X[i], ++cntx;
		}

		while(Y[i]) {
			if (cnty < M/2) sum -= i;
			else if (cnty > M/2)sum += i;
			--Y[i], ++cnty;
		}
	}
	
	cout << sum<< endl;

	return 0;
}

