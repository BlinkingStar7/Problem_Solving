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
#define IFN 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif


int main () {
	int r;
	while(scanf("%d",&r)) {
		if (r == -1) break;
		getchar();
		char input[100];
		gets(input);
		vector<bool> alpha(26, false), beta(26, false);
		for (int i=0; i<strlen(input); ++i) {
			alpha[input[i]-'a'] = true;
		}

		int num=0;
		for (int i=0; i<26; ++i)
			if (alpha[i]) ++num;

		gets(input);
		int wrong=0;
		for (int i=0; i<strlen(input); ++i) {
			if (num == 0 || wrong == 7) break;
			if (!beta[input[i]-'a']) {
				beta[input[i]-'a'] = true;
				if (alpha[input[i]-'a']) --num;
				else ++wrong;
			}
		//	else if (alpha[input[i]-'a'] == false) ++wrong;
		}
		printf("Round %d\n", r);
		if (wrong >= 7) printf("You lose.\n");
		else if (num == 0) printf("You win.\n");
		else printf("You chickened out.\n");

	}
	return 0;
}

