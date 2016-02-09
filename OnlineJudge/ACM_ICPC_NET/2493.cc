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

<<<<<<< HEAD
int N, Cur[10001], Tar[10001], Ans[10001], D[2][10];

int main () {
	cin >> N;
	for (int i=1; i<=N; ++i)
		scanf("%1d", Cur+i);
	for (int i=1; i<=N; ++i)
		scanf("%1d", Tar+i);

	for (int n=1; n<=N; ++n) {
		for (int r=0; r<9; ++r) {
			for (int k=0; k<9; ++k) 
				cand = min (cand, D[(n-1)%2][(r+k)%9] + (Cur[n]+k+9 - Tar[n])%9);
			D[n%2][r] = cand;
		}
	}

	cout 
				
=======
int N, H[500001], Ans[500001];
int main () {
	cin >> N;
	int M=0; 
	for (int i=1; i<=N; ++i) {
		scanf("%d", H+i);

		if (H[i] > M) {
			Ans[i] = 0;
			M = H[i];
		}
		else {
			if (H[i] < H[i-1])
				Ans[i] = i-1;
			else {
				int cur = Ans[i-1];
				while (H[i] > H[cur])
					cur = Ans[cur];
				Ans[i] = cur;
			}
		}
	}

	for (int i=1; i<=N; ++i)
		printf("%d ", Ans[i]);
	puts("");

>>>>>>> 32e996f7eef0b29be9f71bbe3e63151e4af40b76



	return 0;
}

