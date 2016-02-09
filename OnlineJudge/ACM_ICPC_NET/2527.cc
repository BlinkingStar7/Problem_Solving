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

int intersection (int a, int b, int c, int d) {
	if (a > c) {
		swap(a, c);
		swap(b, d);
	}
	return (b < c) ? -1 : min(b, d) - c;
}

int main () {

	for (int i=0; i<4; ++i) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
		int xx1, yy1, xx2, yy2;
		scanf("%d%d%d%d", &xx1,&yy1,&xx2,&yy2);
		
		int x, y;
		x = intersection (x1, x2, xx1, xx2); 
		y = intersection (y1, y2, yy1, yy2);

		if (x > y) swap (x, y);
		if (x == -1) printf("d\n");
		else if (x == 0) {
			if (y == 0) printf("c\n");
			else printf("b\n");
		}
		else printf("a\n");
	}
	return 0;
}

