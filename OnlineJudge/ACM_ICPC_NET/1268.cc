#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif 

long long n, group[1001];
int num[1001];
int main () {
	scanf("%lld",&n);
	for (int i=0; i<n; ++i)
		for (int j=0; j<5; ++j) {
			int t;
			scanf("%d", &t);
			group[i] |= (1LL<<(9*j+(t-1)));
		}

	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (group[i] & group[j]) ++num[i], ++num[j];

	int ans = 0;
	for (int i=0; i<n; ++i) {
		DPRINTF(("%d ", num[i]));
		if (num[i] > num[ans]) ans = i;
	}
	
	printf("%d\n", ans+1);

	return 0;
}

