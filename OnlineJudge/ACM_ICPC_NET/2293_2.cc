#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int coin[111], n, k, memo[2][10001];

int Solve(int cur, int price){

	if(cur == n) return (price % coin[cur] == 0 ? 1 : 0);
	else if(price == 0) return 1;

	int &ret = memo[cur%2][price];

	if(ret != -1) return ret;

	ret = 0;
	for(int i=0; i<=price/coin[cur]; ++i)
		ret += Solve(cur+1, price-i*coin[cur]);

	return ret;
}

int main() {

	memset(memo, -1, sizeof(memo));
	scanf("%d %d", &n, &k);

	for(int i=1; i<=n; ++i)
		scanf("%d", &coin[i]);

	for(int i=n; i>=1; --i){
		for(int j=1; j<=k; ++j)
			Solve(i, j);
	}

	printf("%d", Solve(1, k));

	return 0;
}
