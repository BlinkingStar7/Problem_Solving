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

int testNum, N, explosive[21];
bool isStable(int set) {
	for (int i=0; i<N; ++i)
		if ((set & (1<<i)) && (set & explosive[i]))
			return false;
	return true;
}

int countStable() {
	int ret = 0;
	for (int set=1; set < (1<<N); ++set) {
		if (!isStable(set))
			continue;
		bool isMaximal = true;
		for (int test=0; test<N; ++test)
			if (!(set & (1<<test)) && isStable(set | (1<<test))) {
				isMaximal = false;
				break;
			}
		if (isMaximal)
			++ret;
	}
	return ret;
}

int main () {
	cin >> N;
	
	for (int i=0; i<N; ++i) {
		for (int j=0; j<N; ++j) {
			int e;
			scanf("%d",&e);
			if (e)
				explosive[i] |= (1<<j);
		}
	}

	cout << countStable() << endl;

	return 0;
}

