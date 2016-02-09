#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int N, R[100001], list[100001/3+1][3];

int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		scanf("%d", R+i);
	
	sort(R, R+N);

	priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > q;

	int num = 0;

	for (int i=0; i<N; ++i) {
		if (i == 0 || R[i] == R[i-1])
			++num;
		else {
			q.push(make_pair(num, R[i-1]));
			num = 1;
		}
	}
	q.push(make_pair(num, R[N-1]));

	int ans = 0;
	
	if (q.size() >= 3) {
		pair<int, int> snow[3];
		snow[0] = q.top(), q.pop();
		snow[1] = q.top(), q.pop();
		snow[2] = q.top(), q.pop();
		bool flag = true;
		while (1) {
			for (int i=0; i<3; ++i) {
				if (snow[i].first == 0) {
					if (q.empty()) {
						flag = false;
						break;
					}
					snow[i] = q.top();
					q.pop();
					--i;
					continue;
				}
				else {
					list[ans][i] = snow[i].second;
					--snow[i].first;
				}
			}
			if (!flag)
				break;
			++ans;
		}
	}

	cout << ans << endl;
	for (int i=0; i<ans; ++i) {
		sort(&list[i][0], &list[i][3], greater<int>());
		for (int j=0; j<3; ++j)
			printf("%d ", list[i][j]);
		puts("");
	}
	return 0;
}

