#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

#define MAX_N 1000*1000*10
int tW, Ans[MAX_N+ 1];
void preCalc() {
		for (long long a=1; a*a*a<=MAX_N; ++a) {
			for (long long b=a; b*b<=MAX_N; ++b) {
				for (long long c=b; a*b*c<=MAX_N; ++c) {
					long long cand = a*a+b*b+c*c;
					long long sqrtK = sqrt(cand);
					if (sqrtK*sqrtK == cand) ++Ans[a*b*c];
				}
			}
		}
		for (int i=1; i<=MAX_N; ++i)
			Ans[i] += Ans[i-1];
}

int main() {
	preCalc();

	cin >> tW;
	while (tW--) {
		long long N;
		cin >> N;
		cout << Ans[N] << endl;
	}

	return 0;
}

