#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif 

int main () {
	char input[123456];
	gets(input);
	int ans = 0, len = strlen(input), bar = 0;

	bool lazer = false;
	for (int i=0; i<len; ++i) {
		if (input[i] == '(') {
			++bar;
			lazer = true;
		}
		else if (input[i] == ')') {
			if (lazer) {
				--bar;
				ans += bar;
				lazer = false;
			}
			else {
				--bar;
				ans++;
			}			
		}
	}
	printf("%d\n", ans);
	return 0;
}

