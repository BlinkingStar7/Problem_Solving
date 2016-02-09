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

int N;

int main () {
	cin >> N;
	set<int> s;
	for (int i=0; i<N; ++i) {
		int toFind;
		scanf("%d", &toFind);
		while(1) {
			set<int>::iterator it = s.find(toFind);
			if (it != s.end()) {
				s.erase(it);
				++toFind;
			}
			else {
				s.insert(toFind);
				break;
			}
		}
	}

	cout << s.size() << endl;
			

	return 0;
}

