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
#include <numeric>
using namespace std;

int testNum, N, K;

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> K >> N;
		queue<int> q;
		long long A = 1983, sum = 0;
		int ans = 0;
		for (int i=0; i<N; ++i) {
			sum += A%10000+1;
			q.push(A%10000+1);
			while (sum > K) {
				sum -= q.front();
				q.pop();
			}
			if (sum == K) ++ans;
			A = (A*214013 + 2531011) % (1LL<<32);
		}

		cout << ans << endl;





	}


	return 0;
}

