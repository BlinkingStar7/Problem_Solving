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
#define IFN 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;


int main () {
	while(1) {
		int h,y,d,f;
		cin >> h >> y >> d >> f;
		if (h == 0) break;
		int cur = 0, day = 1, fatigue = y*f;
		h *= 100; y*=100; d*=100;
		bool flag = true;
		while(1) {
			cur += y;
			if (cur > h) break;
			
			cur -= d;
			if (cur < 0) {
				flag = false;
				break;
			}
			++day;
			y = max(0, y-fatigue);
		}

		if (flag) printf("success on day %d\n", day);
		else printf("failure on day %d\n", day);
	}

	return 0;
}

