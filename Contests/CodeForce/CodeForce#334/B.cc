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

int N, K, S[123123];
int main () {
	cin >> N >> K;
	for (int i=0; i<N; ++i)
		scanf("%d", S+i);
	int size = S[N-1];
	for (int i=0; i<N-K; ++i)
		size = max (size, S[i] + S[2*(N-K)-1-i]);

	printf("%d\n", size);
		


	return 0;
}

