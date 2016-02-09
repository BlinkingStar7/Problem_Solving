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

int x, y;
const char X[8][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
const int Day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main () {
	cin >> x >> y;
	int day = 0, cur = 1;

	while (cur < x) 
		day += Day[cur++];

	printf("%s", X[(day+y)%7]);	

	return 0;
}

