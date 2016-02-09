#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int N, P[21], S, A, B, C, ans=0x7fffffff;
bool D[1001][667][21];

int main () {
	
	cin >> N;
	for (int i=0; i<N; ++i) {
		cin >> P[i];
		S += P[i];
	}

	D[0][0][0] = true;

	for (int p=1; p<=N; ++p) 
		for (int b=0; b<1001; ++b) 
			for (int c=0; c<667; ++c) 
				D[b][c][p] = D[b][c][p-1] ||
					(b < P[p] ? false : D[b-P[p]][c][p-1]) ||
					(c < P[p] ? false : D[b][c-P[p]][p-1]);
	
	for (int b=0; b<1001; ++b)
		for (int c=0; c<667; ++c)
			if (D[b][c][N])
				if ((S-(b+c) >= b) && (b >= c) && (S-(b+c)-c<=ans)) {
					ans = S-(b+c)-c, A=S-(b+c), B=b, C=c;
					printf("%d %d %d\n", A, B, C);
				}
	return 0;
}




