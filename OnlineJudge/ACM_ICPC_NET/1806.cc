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

int main() {
	int N, S, D, ans = 987654321, sum =0;
	queue<int> q;
	cin >> N >> S;
	while (N--) {
		cin >> D;
		sum += D;
		q.push(D);
		while (sum >= S) {
			ans = min (ans, (int)q.size());
			sum -= q.front();
			q.pop();
		}
	}
	if (ans == 987654321) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}



