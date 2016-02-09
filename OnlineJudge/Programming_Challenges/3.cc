#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <functional>
using namespace std;

int main() {
	int N;
	double M[1001];
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		int sum = 0;
		for (int i=0; i<N; ++i) {
			double t;
			scanf("%lf", &t);
			M[i] = t*100 + 0.5;
			sum += M[i];
		}
		sort(M, M+N, greater<int>());

		int avg = sum/N, spare = sum - avg*N, over = 0;
		int ans = 0;
		for (int i=0; i<N; ++i) {
			if (spare > 0) --spare, ans += abs(M[i] - (avg+1));
			else ans += abs(M[i] - avg);
		}
		
		ans /= 2;
		
		printf("$%.2lf\n",ans/100.0);
	}


	return 0;
}


