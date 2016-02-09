#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int N, Ans[101];
int main() {
	cin >> N;
	for (int i=0; i<N; ++i) {
		int n, pos = i;
		scanf("%d",&n);
		Ans[i] = i+1;
		while (n > 0) {
			swap(Ans[pos-1], Ans[pos]);
			--n;
			--pos;
		}
	}

	for (int i=0; i<N; ++i)
		printf("%d ", Ans[i]);


	return 0;
}


