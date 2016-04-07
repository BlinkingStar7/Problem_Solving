#include <algorithm>
#include <cstdio>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int n, dp[3001], d[3001], s[3001], t, h;
int main () {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) 
		scanf("%d", d+i);

	std::sort(d+1, d+n+1);
	
	for (int i=1; i<=n; i++) 
		s[i] = s[i-1] + d[i];
	
	scanf("%d%d", &t, &h);
	
	for (int i=1; i<=n; ++i) {
		dp[i] = s[i]*t;
		for (int j=1; j<=i; ++j) 
			dp[i] = MIN(dp[i], dp[j-1] + (s[i]+s[j-1]-2*s[(i+j)/2] + (i-j+1)%2*d[(i+j)/2])*t + h);
	}
	printf("%d\n", dp[n]);

	return 0;
}
