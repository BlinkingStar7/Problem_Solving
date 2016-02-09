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
	char s[1000001];
	scanf("%s", s);

	int cur = strlen(s)-1;
	vector<int> a;
	while (1) {
		if (cur < 0) break;
		int num=0, base = 1;
		for (int i=0; i<min(3, 1+cur); ++i, base*=2)
			num += (s[cur-i]-'0')*base;
		a.push_back(num);
		cur -= 3;

	}

	for (int i=a.size()-1; i>=0; --i)
		printf("%d", a[i]);


	return 0;
}

