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

int N;
pair<pair<int, int>, pair<int, int> > Flower[100001];

int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a,&b,&c,&d);
		Flower[i] = make_pair(make_pair(a,b),make_pair(c,d));
	}

	sort(Flower, Flower+N);

	Flower[N] = make_pair(make_pair(12,31), make_pair(12,31));

	int cnt = 0;
	pair<int, int> today = make_pair(3, 1), maximum = make_pair(1, 1);

	for (int i=0; i<=N; ++i) {
		if (today > make_pair(11, 30)) break;
		if (Flower[i].first > today) {
			if (maximum == today) {
				cout << 0 << endl;
				return 0;
			}
			else {
				++cnt;
				today = maximum;
				--i;
				continue;
			}
		}
		else
			maximum = max(maximum, Flower[i].second);
	}

	cout << cnt << endl;


	return 0;
}

