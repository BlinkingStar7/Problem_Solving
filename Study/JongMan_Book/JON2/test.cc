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

int testNum;

int main () {
	cin >> testNum;
	cout << testNum;

	while (testNum--) {
		cout << 5 << endl;
		for (int j=0; j<5; ++j) {
			int l = rand()%10 + 1;
			for (int i=0; i<l; ++i)
				printf("%c", 'a'+(rand()%26));
			puts("");
		}


	}


	return 0;
}

