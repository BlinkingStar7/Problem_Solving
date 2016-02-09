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

int N, rank[51];
pair<int, int> A[51];

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%d%d", &A[i].first, &A[i].second);

	for (int i=0; i<N; ++i)
		rank[i] = 1;

	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j) {
			if (A[j].first>A[i].first && A[j].second>A[i].second)
				++rank[i];
		}

	for (int i=0; i<N; ++i)
		printf("%d ",rank[i]);


	return 0;
}

