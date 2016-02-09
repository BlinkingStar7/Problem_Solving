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
#include <set>
#include <numeric>
using namespace std;

int N, A[5001], D[5001][2];

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%d", A+i);

	for (int j=1; j<=N-1; ++j) 
		for (int i=j-1; i>=0; --i) {
			if (A[i] == A[j]) D[i][j%2] = D[(i+1)][(j-1)%2];
			else D[i][j%2] = 1 + min(D[(i+1)][j%2], D[i][(j-1)%2]);
		}

	cout << D[0][(N-1)%2] << endl;

	return 0;
}

