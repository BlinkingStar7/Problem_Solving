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

int num[27];
int main () {
	string s;
	cin >> s;
	for (int i=0; i<s.size(); ++i)
		num[tolower(s[i])-'a']++;

	int M=-1, flag = 0;
	for (int i=0; i<26; ++i)
		if (M==-1 || num[i] > num[M]) {
			M = i;
			flag = 0;
		}
		else if (num[i] == num[M])
			flag = 1;
	if (flag) printf("?\n");
	else printf("%c\n", 'A'+M);
	return 0;
}

