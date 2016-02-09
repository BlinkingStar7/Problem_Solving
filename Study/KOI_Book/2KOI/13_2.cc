#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int N, W, C[101], M[101], memo[102][10002];

int main () {
	cin >> N >> W;
	for (int i=0; i<N; ++i) {
		cin >> M[i];
		cin >> C[i];
	}

	for (int i=N; i>=0; --i) {
		for (int j=0; j<=W; ++j) {
			if (M[i] + j > W) memo[i][j] = memo[i+1][j];
			else memo[i][j] = max(memo[i+1][j], C[i] + memo[i+1][j+M[i]]);
		}
	}


	cout << memo[0][0] << endl; 
	return 0;
}

