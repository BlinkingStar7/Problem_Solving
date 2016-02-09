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

char A[6] = {"DCBAE"};
int main () {
	for(int i=0; i<3;++i) {
		int s=0, x;
		for(int j=0; j<4; ++j) {
			scanf ("%d", &x);
			s+=x;
		}
		printf("%c\n", A[s]);
	}
	return 0;
}

