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

bool Board[101][101];

int main () {
	int N, ans=0;
	cin >> N;
	for (int i=0; i<N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int y=0; y<10; ++y)
			for (int x=0; x<10; ++x)
				if (!Board[a+y][b+x]) {
					Board[a+y][b+x] = true;
					++ans;
				}
	}

	cout << ans << endl;


	return 0;
}

