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
#include <list>
#include <iterator>
using namespace std;

int testNum, N, K;

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> K;
		list<int> soldier(N);
		list<int>::iterator it;
		int cnt = 1;
		for (it = soldier.begin(); it != soldier.end(); ++it) 
			*it = cnt++;
		it = soldier.begin();
		while(soldier.size() > 2) {
			list<int>::iterator next = std::next(it, 1);
			soldier.erase(it);
			for (int j=0; j<K-1; ++j) {
				if (next == soldier.end())
					next = soldier.begin();
				next = std::next(next, 1);
			}
			if (next == soldier.end())
				next = soldier.begin();
			it = next;
		}

		vector<int> ans;
		ans.push_back(soldier.front()); ans.push_back(soldier.back());
		sort(ans.begin(), ans.end());
		printf("%d %d\n", ans[0], ans[1]);

	}


	return 0;
}

