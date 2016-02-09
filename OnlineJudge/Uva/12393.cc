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

int N, IDT[1<<22];
int getMin (int a, int b) {
	int ret = 987654321;
	while (a < b) {
		if (a%2==1) ret = min(ret, IDT[a++]);
		if (b%2==0) ret = min(ret, IDT[b--]);
		a>>=1, b>>=1;
	}
	if (a == b) ret = min(ret, IDT[a]);
	return ret;
}

int main () {
	while(1) {
		cin >> N;
		if (!N) break;

		int base = 1;
		for (; base<2*N; base<<=1);

		for (int i=0; i<N; ++i) {
			scanf("%d", &IDT[base+i]);
			IDT[base+i+N] = IDT[base+i];
		}

		for (int i=1; i<2*N; ++i)
			IDT[base+i] += IDT[base+i-1];

		for (int i=base-1; i>0; --i)
			IDT[i] = min (IDT[i*2], IDT[i*2+1]);

		int ans = 0;
		for (int i=0; i<N; ++i) {
			int threshold = (i==0 ? 0 : IDT[base+i-1]);
			if (getMin(base+i, base+i+N-1) >= threshold)
				++ans;
		}

		cout << ans << endl;
	}
	return 0;
}

