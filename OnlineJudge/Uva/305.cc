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

int K;
int main () {
	while (1) {
		cin >> K;
		if (!K) break;
		list<int> people;
		for (int i=0; i<2*K; ++i) {
			if (i<K) people.push_back(1);
			else people.push_back(0);
		}

		for (int m=1; ; ++m) {
			list<int> cur = people;
			list<int>::iterator it = cur.begin();
			int size = 2*K;
			while (size > K) {
				for (int i=0; i<m-1; ++i){
					if(it == cur.end()) it = cur.begin();
					++it;
				}
				if(it == cur.end()) it = cur.begin();
				if (*it) break;
				--size;
				it = cur.erase(it);
			}
			if (size == K) {
				cout << m << endl;
				break;
			}
		}
	}



	return 0;
}

