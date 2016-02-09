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


int main () {
	int N, A[51], B[51];
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%d",A+i);
	
	for (int i=0; i<N; ++i)
		scanf("%d",B+i);

	sort(A, A+N);
	sort(B, B+N, greater<int>());

	int s = 0;
	for (int i=0; i<N; ++i)
		s += A[i]*B[i];

	printf("%d\n", s);
	

	return 0;
}

