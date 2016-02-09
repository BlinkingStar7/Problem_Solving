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
int main () {
	int Min=987654321, Max=-1;
	cin >> N;
	for (int i=0; i<N; ++i) {
		int temp;
		scanf("%d",&temp);
		Min = min(Min, temp);
		Max = max(Max, temp);
	}

	printf("%d\n", Min*Max);

	return 0;
}

