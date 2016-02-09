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

int N;
int main () {
	while(1) {
		cin >> N;
		if (!N) break;
		list<int> cities;
		for (int i=1; i<=N; ++i)
			cities.push_back(i);

		for (int m=1; m<=N; ++m) {
			list<int> cur = cities;
			int size = N;
			list<int>::iterator it = cur.begin();
			while(size > 1) {
				it = cur.erase(it);
				--size;
				for (int i=1; i<m; ++i) {
					if (it == cur.end()) it = cur.begin();
					++it;
				}
				if (it == cur.end()) it = cur.begin();
			}
			if (cur.front() == 13) {
				cout << m << endl;
				break;
			}
		}
	}
				

	return 0;
}

