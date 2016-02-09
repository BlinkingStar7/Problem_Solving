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


int N, Score[302], D[3][2];
int main () {
	cin >> N;
	for (int i=1; i<=N; ++i) 
		scanf("%d", Score+i);

	D[1][0] = Score[1];
	for (int cur=2; cur <=N; ++cur) {
		for (int c=0; c<2; ++c) {
			int &n = D[cur%3][c];
			n = Score[cur];
			if (c == 0) {
				n += max (D[(cur-2)%3][0], D[(cur-2)%3][1]);
			}
			else
				n += D[(cur-1)%3][c-1];
		}
	}


	cout << max( D[N%3][0], D[N%3][1] ) << endl;
				


	return 0;
}

