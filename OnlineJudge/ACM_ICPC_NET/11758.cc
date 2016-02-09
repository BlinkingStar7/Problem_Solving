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
	int x[3], y[3];
	for (int i=0; i<3; ++i)
		scanf("%d%d",x+i,y+i);
	int t = (x[1]-x[0])*(y[2]-y[0]) - (x[2]-x[0])*(y[1]-y[0]);
	printf("%d\n", t>0?1:t==0?0:-1);

	return 0;
}

