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

int N, D[100001];
int main () {
	cin >> N;

	for (int i=1; i<=N; ++i) {
		int sqrti = sqrt(i);
		int cand = 987654321;
		for (int j=1; j<=sqrti; ++j) {
			cand = min (cand, D[i-j*j]+1);
		}
		D[i] = cand;
	}

	cout << D[N] << endl;

	
		

	return 0;
}

