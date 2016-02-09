#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int N, Mem[41];
int F(int n) {
	if (n == 0 || n == 1) return 1;
	int &ret = Mem[n];
	if (ret != 0) return ret;

	return ret = F(n-1) + F(n-2);
}

int main() {
	int tN;
	cin >> tN;

	while (--tN >= 0) {
		cin >> N;
		if (N == 0) cout << "1 0" << endl;
		else if (N == 1) cout << "0 1" << endl;
		else
			printf("%d %d\n", F(N-2), F(N-1));
	}

	return 0;
}


