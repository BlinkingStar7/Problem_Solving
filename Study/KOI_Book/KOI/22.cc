#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int cnt = 0, W[101], N, C[101][101];

int main() {
	cin >> N;
	for (int i=0; i<N; ++i) {
		int f, t;
		cin >> f >> t;
		W[f] = t;
	}

	for (int f=1; f<=N; ++f)
		for (int c=1; c<=N; ++c)
			if (W[f] * W[c] != 0 && (f-c) * (W[f] - W[c]) < 0) 
				C[f][c] = 1;

	while(1) {
		int max = 0, ind = 0;
		for (int i=1; i<=N; ++i) {
			int c = 0;
			for (int j=1; j<=N; ++j)
				if (C[i][j]) ++c;
			if (c > max) {
				max = c;
				ind = i;
			}
		}
		if (max == 0) break;
		++cnt;
		for (int i=0; i<N; ++i)
			if (C[ind][i]) C[ind][i] = C[i][ind] = 0;
	}

	cout << cnt << endl;
	return 0;
}





		

