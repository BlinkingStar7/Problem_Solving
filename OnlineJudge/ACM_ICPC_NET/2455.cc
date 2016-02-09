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
	int sum=0, max=0, in, out;
	for (int i=0; i<4; ++i) {
		scanf("%d %d", &out, &in);
		sum += (in-out);
		if (sum > max)
			max = sum;
	}
	cout << max << endl;
		


	return 0;
}

