#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main () {
	int a, b;
	cin >> a >> b;

	printf("%d %d\n", min(a, b), abs(a-b)/2);
	return 0;
}

