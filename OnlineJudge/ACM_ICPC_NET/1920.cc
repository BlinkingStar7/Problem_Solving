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

int N, A[100001];
int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		scanf("%d", A+i);
	}
	sort(A, A+N);

	int M;
	cin >> M;
	for (int i=0; i<M; ++i) {
		int t;
		scanf("%d", &t);
		if (binary_search(A, A+N, t))
			printf("1\n");
		else
			printf("0\n");
	}


	return 0;
}

