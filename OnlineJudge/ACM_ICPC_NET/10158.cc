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

int w, h, p, q, t;
int main () {
	scanf("%d%d%d%d\n", &w,&h,&p,&q);
	scanf("%d",&t);

	printf("%d ", ((p+t)/w)%2 ? w - (p+t)%w : (p+t)%w);
	printf("%d\n", ((q+t)/h)%2 ? h - (q+t)%h : (q+t)%h);

	return 0;
}

