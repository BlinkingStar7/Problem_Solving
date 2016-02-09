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
	int a, b, n; 
	cin >> n ;
	for (int i=0; i<n; ++i) {
		scanf("%d%d",&a,&b);
		if (a%10 == 0) {
			printf("10\n");
			continue;
		}
		int x = a%10;
		for (int j=0; j<b%4 + 3 ; ++j)
			x *= a%10;
		printf("%d\n", x%10);
	}


	return 0;
}

