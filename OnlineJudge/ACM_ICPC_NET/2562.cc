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


int main () {
	int max=0, j=0;
	for (int i=0; i<9; ++i) {
		int x;
		scanf("%d", &x);
		if (x > max) {
			max = x;
			j = i;
		}
	}
	cout << max << endl << j+1 << endl;


	return 0;
}

