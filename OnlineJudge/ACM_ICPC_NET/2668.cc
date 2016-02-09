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
#include <map>
#include <numeric>
using namespace std;

int N, A[101];
int main () {
	cin >> N;
	for (int i=1; i<=N; ++i)
		scanf("%d", A+i);

	vector<bool> selected(N+1);
	int ans = 0;
	for (int i=1; i<=N; ++i) {
		if (!selected[i]) {
			vector<bool> up = selected, down = selected;
			int cur = i, num = 0;
			bool flag = true;
			
			while(1) {
				if (up[cur]) {
					break;
				}
				up[cur] = true;
				if (down[A[cur]]) {
					flag = false;
					break;
				}
				down[A[cur]] = true;
				++ num;
				cur = A[cur];
			}
			if (flag) {
				ans += num;
				selected = up;
			}
		}
	}
	cout << ans << endl;
	for (int i=1; i<=N; ++i)
		if (selected[i])
			printf("%d\n", i);



	return 0;
}

