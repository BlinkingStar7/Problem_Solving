#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {

	printf("%.10lf",(7.0/100)*100);
	double ans = 0;
	for (int i=0; i<1000; ++i) {
		if ((ans/100+0.5)*100 != ans ) printf("%lf %d\n", ans, i);
		ans += 1;
	}


	return 0;
}


