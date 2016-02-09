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

int N;
double rad[100001];
const double PI = 3.141592653589793238462643;

int main () {
	cin >> N;
	for (int i=0; i<N; ++i) {
		int x, y;
		scanf("%d %d", x, y);
		if (y > 0) rad[i] = acos((double)x/sqrt(x*x+y+y));
		else rad[i] = PI + acos((double)x/sqrt(x*x+y+y));
	}

	sort (A, A+N);
	double Min = rad[i];
	for (int i=0; i<N-1; ++i) {

		
	return 0;
}

