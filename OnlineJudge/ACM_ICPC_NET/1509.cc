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
#include <set>
#include <numeric>
using namespace std;

int num[28];
char ans[51];
int main () {
	string S;
	cin >> S;
	int N = S.size();

	for (int i=0; i<N; ++i)
		++num[S[i]-'a'];

	for (int i=0; i<28; ++i) {
		if (num[i] > N/2 + N%2) {
			cout << -1 << endl;
			return 0;
		}
	}

	int mid = (N+1)/2, index = 0;
	for (int i=0; i<28; ++i) {
		if (index >= mid) break;
		if (index + num[i] - 1 >= mid) {
			int n = mid - index, m = num[i] - n;
			for (int j=0; j<n; ++j)
				ans[index++] = 'a' + i;
			index += n - N%2;
			for (int j=0; j<m; ++j)
				ans[index++] = 'a' + i;
			num[i] = 0;
		}
		else {
			for (; num[i]; --num[i])
				ans[index++] = 'a'+i;
		}
	}

	index = 0;

	for (int i=0; i<28; ++i) {
		for (; num[i]; --num[i]) {
			while (ans[index] != '\0') 
				++index;
			ans[index++] = 'a'+i;
		}
	}

	ans[N] = '\0';
	printf("%s\n", ans);



	return 0;
}

