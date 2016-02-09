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
int map[129][129], N;

bool isSame (int y, int x, int size) {
	for (int i=y; i<y+size; ++i)
		for (int j=x; j<x+size; ++j)
			if (map[i][j] != map[y][x])
				return false;
	return true;
}

int Solve(int y, int x, int size, int t) {
	if (isSame (y, x, size)) return map[y][x] == t ? 1 : 0;

	return Solve(y, x, size/2, t) + Solve(y+size/2,x+size/2,size/2,t) 
		+ Solve(y+size/2,x,size/2,t) + Solve(y,x+size/2,size/2,t);
}

int main () {
	cin >> N;

	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			scanf("%d", &map[i][j]);
	cout << Solve(0, 0, N, 1) << endl;
	cout << Solve(0, 0, N, 0) << endl;


	return 0;
}

