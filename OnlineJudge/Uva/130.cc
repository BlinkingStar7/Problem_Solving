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
using namespace std;

int N, K;
int main () {
	while(1) {
		cin >> N >> K;
		if (N == 0 && K == 0) break;
		list<int> soldier;
		for (int i=1; i<=N; ++i)
			soldier.push_back(i);

		for (int first=1; first<=N; ++first) {
			list<int> cur = soldier;
			list<int>::iterator it = cur.begin();
			for (int i=0; i<first-1; ++i)
				++it;
			int size = N;

			while(size > 1) {
				for (int i=0; i<K-1; ++i) {
					if (it == cur.end()) it = cur.begin();
					++it;
				}
				if (it == cur.end()) it = cur.begin();
				it = cur.erase(it);
				--size;

				list<int>::iterator toInsert = it;
				for (int i=0; i<K-1; ++i) {
					if (it == cur.end()) it = cur.begin();
					++it;
				}
				if (it == cur.end()) it = cur.begin();

				cur.insert(toInsert, *it);
				if (it == toInsert)
					it = cur.erase(it);
				else {
					cur.erase(it);
					it = toInsert;
				}
			}
			if (cur.front() == 1) {
				cout << first << endl;
				break;
			}
		}
	}


	return 0;
}

