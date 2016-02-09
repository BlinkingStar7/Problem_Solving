#include <iostream>
#define MIN -987654321
using namespace std;

int N, Board[11][11], D1[19], D2[19];
int isSafe (int i, int j) {return i>=0&&j>=0&&i<N&&j<N;}
int Solve (int d2) {
	if (d2 == 2*N) return 0;

	int ret = MIN;
	for (int i=0; i<N; ++i) {
		int j = d2 - i;
		if (isSafe (i, j) && Board[i][j] && !D2[d2] && !D1[i-j+N-1]) {
			D2[d2] = D1[i-j+N-1] = 1;
			ret = max (ret, 1+ Solve(d2+1));
			D2[d2] = D1[i-j+N-1] = 0;
		}
	}
	return ret = max (ret, Solve(d2+1));
}

int main() {
	cin >> N;
	for (int i=0; i<N; ++i) 
		for (int j=0; j<N; ++j)
			cin >> Board[i][j];

	cout << Solve(0) << endl;
	return 0;
}

