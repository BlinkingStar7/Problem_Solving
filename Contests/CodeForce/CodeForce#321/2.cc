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

int N, D, Till[100001];
long long IDT[1<<18];
pair<int, int> M[100001];

long long getSum (int a, int b) {

	long long sum =0;
	while (a < b) {
		if (a%2) sum += IDT[a++];
		if (!(b%2)) sum += IDT[b--];
		a>>=1, b>>=1;
	}
	if (a==b) sum += IDT[a];
	return sum;
}

int main () {
	cin >> N >> D;
	
	int base;
	for (base=1; base<N; base*=2);

	for (int i=0; i<N; ++i) 
		scanf("%d %d", &M[i].first, &M[i].second);
	
	sort(&M[0], &M[N]);

	for (int i=0; i<N; ++i)
		IDT[base+i] = M[i].second;

	for (int i=base-1; i>=1; --i)
		IDT[i] = IDT[2*i] + IDT[2*i+1];

	for (int i=0; i<N; ++i) {
		int t;
		for (t = (i == 0) ? 1 : Till[i-1]; t<N; ++t)
			if (M[t].first >= M[i].first + D) break;
		Till[i] = t-1;
	}

	long long ans=0;
	for (int start=0; start<N; ++start) {
		long long ret = getSum(base+start, base + Till[start]);
		if (ret >= ans)
			ans = ret;
	}

	cout << ans << endl;
	return 0;
}

