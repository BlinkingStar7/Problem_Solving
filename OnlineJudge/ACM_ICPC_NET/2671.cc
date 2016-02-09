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

const int DFA[2][10] = {
	{1, 9, 1, 4, 5, 5, 1, 8, 5, 9},
	{3, 2, 3, 9, 9, 6, 7, 7, 2, 9}};

int main () {
	char str[151];
	while (scanf("%s", str) != EOF) {
		int len = strlen(str), state = 0;
		for (int i=0; i<len; ++i)
			state = DFA[str[i]-'0'][state];
		if (state == 2 || state == 6 || state == 7)
			printf("SUBMARINE\n");
		else
			printf("NOISE\n");
	}
	
	return 0;
}

