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

const int MAX = 987654321;
int From[10001], To[10001], N, D[10001][10];
int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%1d", From+i);
	for (int i=0; i<N; ++i)
		scanf("%1d", To+i);

	for (int n=N-1; n>=0; --n) {
		for (int l=0; l<10; ++l) {
			int m=MAX, mk = 0;
			for (int k=0; k<10; ++k) {
				int cand = D[n+1][(l+k)%10] + k + (From[n]+l+k-To[n]+10)%10;
				if (cand < m) 
					m = cand;
			}
			D[n][l] = m;
		}
	}
	
	cout << D[0][0] << endl;
	
	int cur = 0;

	for (int i=0; i<N; ++i) {
		int target = D[i][cur];
		for (int l=0; l<10; ++l) {
			if (D[i+1][(cur+l)%10] + l + (From[i]+l+cur-To[i]+10)%10 == target) {
				int left=l, right=(From[i]+l+cur-To[i]+10)%10;
				if (left) printf("%d %d\n", i+1, left);
				if (right) printf("%d %d\n", i+1, -right);
				cur = (cur+l)%10;
				break;
			}
		}
	}

	return 0;
}

