#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000*1000;
int Ans[MAXN+1];

void preCalc() {
	Ans[1] = 1;
	for (int i=2; i<=MAXN; ++i) {
		long long num = i, x = 1;
		while (num != 1) {
			++x;
			if (num%2) num = num*3 + 1;
			else num /=2;
		}
		Ans[i] = x;
	}
}		
		
int main() {
	int I, J;
	preCalc();
	while (scanf("%d %d", &I, &J) != EOF) {
		int max = 0;
		printf("%d %d ", I, J);
		if (J < I) swap(I, J);
		for (int i=I; i<=J; ++i)
			if (Ans[i] > max) max = Ans[i];
		printf("%d\n", max);
	}
	return 0;
}


