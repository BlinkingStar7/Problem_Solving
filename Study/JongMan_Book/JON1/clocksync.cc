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
using namespace std;

#define MAX 987654321
const char S[10][17] = {
   //0123456789012345
	"oooxxxxxxxxxxxxx",
	"xxxoxxxoxoxoxxxx",
	"xxxxoxxxxxoxxxoo",
	"oxxxooooxxxxxxxx",
	"xxxxxxoooxoxoxxx",
	"oxoxxxxxxxxxxxoo",
	"xxxoxxxxxxxxxxoo",
	"xxxxooxoxxxxxxoo",
	"xoooooxxxxxxxxxx",
	"xxxoooxxxoxxxoxx"};

int C, A[17];

void Switch (int s) {
	for (int i=0; i<16; ++i)
		if (S[s][i] == 'o')
			A[i] += 3;
}
int Solve (int s) {
	if (s == 10) {
		for (int i=0; i<16; ++i)
			if (A[i] % 12 != 0) return MAX;
		return 0;
	}

	int ret = MAX;

	for (int i=0; i<=3; ++i) {
		ret = min (ret, i + Solve(s+1));
		Switch (s);
	}

	return ret;
}

		
int main () {
	cin >> C;
	
	while (C--) {
		for (int i=0; i<16; ++i)
			cin >> A[i];
		int ret = Solve(0);
		if (ret == MAX) cout << -1 << endl;
		else cout << Solve (0) << endl;
	}

	return 0;
}

