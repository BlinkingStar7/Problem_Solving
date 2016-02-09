#include <iostream>
#include <cstdio>
using namespace std;
int N, R[14], D1[28], D2[28];

int Solve (int n) {
	if (n == N) return 1;
	int ret = 0;
	for (int i=0; i<N; ++i) {
		if (!R[i] && !D1[i+n] && !D2[i-n+N-1]) {
			R[i] = 1; D1[i+n] = 1; D2[i-n+N-1] = 1;
			ret += Solve (n+1);
			R[i] = 0; D1[i+n] = 0; D2[i-n+N-1] = 0;
		}
	}
	return ret;
}


int main () {
	cin >> N;
	cout << Solve (0) << endl;
	return 0;
}

