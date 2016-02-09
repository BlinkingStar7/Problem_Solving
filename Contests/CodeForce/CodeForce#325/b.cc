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
using namespace std;

int N, A[51], B[51], C[51];
int main () {
	cin >> N >> A[0];

	for (int i=1; i<N-1; ++i) {
		cin >> A[i];
		A[i] += A[i-1];
	}

	cin >> B[0];

	for (int i=1; i<N-1; ++i) {
		cin >> B[i];
		B[i] += B[i-1];
	}

	for (int i=0; i<N; ++i)
		cin >> C[i];

	int D[51];

	for (int i=0; i<N; ++i)
		D[i] = C[i] + (i==0? 0 : A[i-1]) + B[N-2] - (i==0? 0 : B[i-1]);

	sort(D, D+N);

	cout << D[0] + D[1] << endl;



	return 0;
}

