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

int tN;
int main () {
	setbuf(stdout, NULL);
	cin >> tN;
	for (int t=1; t<=tN; ++t) {
		int num, base;
		scanf("%d", &num);
		if (num == 2) {
			printf("Case #%d\n",t);
			printf("3\n");
			continue;
		}

		int sqrtN = sqrt(num), flag;

		for (base = 2; base <= sqrtN; ++base) {
			int N = num, R = num%base;
			flag = 1;
			while (N/=base) {
				if (N%base != R) {
					flag = 0;
					break;
				}
			}
			if (flag) break;
		}

		printf("Case #%d\n",t);
		if (flag)
			printf("%d\n", base);
		if (!flag) {
			for (int x=sqrtN; x>=1; --x)
				if (num%x==0 && x<=(num/x)-2) {
					printf("%d\n", (num/x)-1);
					break;
				}

		}


	}
		
	return 0;
}

