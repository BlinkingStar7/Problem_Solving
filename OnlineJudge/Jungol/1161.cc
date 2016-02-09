#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

void Solve (int num, int a, int b, int c) {
	if (num == 0) return;
	Solve (num-1, a, c, b);
	printf("%d : %d -> %d\n", num, a, c);
	Solve (num-1, b, a, c);
}

int main() {
	int n;
	cin >> n;
	Solve (n, 1, 2, 3);
	return 0;
}


