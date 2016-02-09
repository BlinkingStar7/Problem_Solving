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
	string s[5];
	for (int i=0; i<5; ++i)
		cin >> s[i];

	for (int i=0; i<15; ++i)
		for (int j=0; j<5; ++j) {
			if (i<s[j].size())
				putchar(s[j][i]);
		}


	return 0;
}

