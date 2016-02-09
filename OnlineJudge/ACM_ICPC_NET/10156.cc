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
	int k, n, m;
	cin >> k >> n >> m;
	printf("%d\n", (n*k-m) > 0 ? n*k-m : 0);

	return 0;
}

