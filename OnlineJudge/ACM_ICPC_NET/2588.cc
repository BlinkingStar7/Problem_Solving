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
	int a, b;
	cin >> a >> b;
	int ans = a*b;

	for (int i=0; i<3; ++i) {
		printf("%d\n", a*(b%10));
		b/=10;
	}
	cout << ans << endl;

	return 0;
}

