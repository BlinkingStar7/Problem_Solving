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

inline unsigned int getHex (unsigned int from) {
	unsigned int ret = 0;
	ret |= (from & 0xFF000000) >> 24;
	ret |= (from & 0x00FF0000) >> 8;
	ret |= (from & 0x0000FF00) << 8;
	ret |= (from & 0x000000FF) << 24;
	return ret;
}

int main () {
	int num;
	while (scanf("%d", &num) != EOF) {
		printf("%d converts to %d\n", num, (int)getHex(num));
	}

	return 0;
}

