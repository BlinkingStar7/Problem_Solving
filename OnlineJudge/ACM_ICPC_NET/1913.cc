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
#include <numeric>
using namespace std;

const int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
int A[1000][1000], N, F;

int main () {
	cin >> N >> F;
	int len = N, flag = 1, x=0, y=-1, ax, ay, num = N*N;
	for (int flag=0; flag<2*N-1; ++flag) {
		for (int i=0; i<len; ++i) {
			y += dy[flag%4];
			x += dx[flag%4];
			A[y][x] = num--;
		}
		if (flag%2 == 0) --len;
	}

	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			printf("%d ", A[i][j]);
			if (A[i][j] == F) {
				ay=i+1, ax=j+1;
			}
		}
		cout << endl;
	}

	cout << ay << " " << ax;


		


	return 0;
}

