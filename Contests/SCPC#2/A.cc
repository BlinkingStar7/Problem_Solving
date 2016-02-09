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

int testNum, M;

long long GCD (long long a, long long b) {
	return a==0 ? b : GCD(b%a, a);
}

int main () {
	cin >> testNum;

	for (int tn=1; tn<=testNum; ++tn) {
		cin >> M;
		long long gcd = 0, prev;
		int zeroNum = 0;

		scanf("%lld", &prev);
		for (int i=1; i<M; ++i) {
			long long temp;
			scanf("%lld", &temp);
			if (temp == prev)
				++zeroNum;

			gcd = GCD (temp-prev, gcd);
			prev = temp;
		}

		int ans=0;
		if (zeroNum) {
			ans = zeroNum == M-1 ? 1 : 0;
		}
		else {
			ans = 1;
			long long sqrtN = sqrt(gcd);
			for (int i=2; i<=sqrtN; ++i) {
				int p=0;
				while (gcd%i==0) {
					++p;
					gcd/=i;
				}
				ans *= p+1;
			}
			if (gcd != 1) ans *= 2;
		}
		printf("Case #%d\n%d\n", tn, ans);
	}


	return 0;
}

