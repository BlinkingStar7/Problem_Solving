#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int D[30][30];
int N, M;
int main() {
	int tN;
	cin >> tN;
	for (int n=1; n<30; ++n)
		for (int m=n; m<30; ++m)
			if (n == 1) D[n][m] = m;
			else if (n == m) D[n][m] = 1;
			else if (n < m) {
				for (int next=m-1; next>=n-1; --next)
					D[n][m] += D[n-1][next];
			}
	while (--tN >= 0) {
		cin >> N >> M;
		cout << D[N][M] << endl;
	}

	return 0;
}


