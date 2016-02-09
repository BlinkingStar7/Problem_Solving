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
#include <numeric>
#include <map>
using namespace std;

int testNum, N;

int main () {
	cin >> testNum;

	while (testNum--) {
		int num=0;
		map<int, int> pMap, qMap;
		cin >> N;
		for (int i=0; i<N; ++i) {
			int p, q;
			scanf("%d %d", &p, &q);
			map<int, int>::iterator it = pMap.upper_bound(p);
			int flag = 1;
			while (it != pMap.end()) {
				if (q < qMap.find(it->first)->second) {
					flag = 0;
					break;
				}
				++it;
			}
			if (flag) {
				qMap[i] = q, pMap[i] = p;
				it = pMap.lower_bound(p);
				while (it != pMap.end() && it != pMap.begin()) {
					if (qMap.find(it->first)->second < q) {
						qMap.erase(qMap.find(it->first));
						pMap.erase(it);
						--it;
						--it;
					}
					else
						--it;
				}
			}
			num += qMap.size();
		}
		cout << num << endl;



			


	}


	return 0;
}

