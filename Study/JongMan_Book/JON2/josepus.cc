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
#include <list>
#include <iterator>
using namespace std;

int testNum, N, K;

int main () {
	cin >> testNum;

	while (testNum--) {
		cin >> N >> K;
		queue<int> q;
		for (int i=0; i<N; ++i)
			q.push (i);
		while (q.size() > 2) {
			q.pop();
			for (int i=0; i<K-1; ++i) {
				q.push (q.front());
				q.pop ();
			}
		}
		cout << q.front() << " " << q.back() << endl;
	}





	return 0;
}

