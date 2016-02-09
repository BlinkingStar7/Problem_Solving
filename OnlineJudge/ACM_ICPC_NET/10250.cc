#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int tN;
	cin >> tN;

	while (--tN >= 0) {
		int H, W, N;
		cin >> H >> W >> N;
		int xx = N%H == 0 ? H : N%H, yy = (N-1)/H+1;
		cout << xx;
		if (yy < 10) cout << 0;
		cout << yy << endl;

	}

	return 0;
}


