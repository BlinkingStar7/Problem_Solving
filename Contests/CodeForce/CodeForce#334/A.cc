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

int M[6], W[6];
int main () {
	int total = 0;
	for (int i=1; i<=5; ++i)
		scanf("%d", M+i);
	for (int i=1; i<=5; ++i) {
		scanf("%d", W+i);
		total += max (150*i, (500-2*M[i])*i - 50*W[i]);
	}

	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", total + a*100 - b*50);



		


	return 0;
}

