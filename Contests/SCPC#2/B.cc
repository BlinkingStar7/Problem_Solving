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

int testNum, a, b, c, A[1000001], B[1000001];

int main () {
	cin >> testNum;

	for (int tn=1; tn<=testNum; ++tn) {
		printf("Case #%d\n", tn);
		
		cin >> a >> b >> c;
		for (int i=0; i<c; ++i) {
			int n, k;
			scanf("%d %d", &n, &k);
			for (int i=1; i<=n; ++i) {
				int la=i-a*k, ra=i-a, lb=i-b*k, rb=i-b;
				if (la < 0) la=1;
				if (lb < 0) lb=1;

				if (i<=a) {
					A[i] = 0;
					if (i<=b)
						B[i] = 0;
					else
						B[i] = (A[rb]-A[lb-1]==(rb-lb+1) ? 0 : 1) + B[i-1];
				}
				else {
					A[i] = (B[ra]-B[la-1]==(ra-la+1) ? 0 : 1) + A[i-1];
					if (i<=b)
						B[i] = 0;
					else
						B[i] = (A[rb]-A[lb-1]==(rb-lb+1) ? 0 : 1) + B[i-1];
				}
			}
			if (A[n]-A[n-1]) printf("a");
			else printf("b");
		}
		puts("");
	}

	return 0;
}

