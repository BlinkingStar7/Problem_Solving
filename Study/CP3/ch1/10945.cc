#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define IFN 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<string> vs;

int main () {
	char input[100];
	while (gets(input)) {
		if (strcmp(input, "DONE") == 0) break;
		bool palindrome = true;
		int lo = 0, hi = strlen(input)-1, len = strlen(input);
		while (hi > lo) {
			while(lo < len && !isalpha(input[lo])) ++lo;
			while(hi >= 0 && !isalpha(input[hi])) --hi;
			if (lo == len || hi < 0 || lo >= hi) break;
			if (tolower(input[lo]) != tolower(input[hi])) {
				palindrome = false;
				break;
			}
			++lo, --hi;
		}

		if (palindrome) printf("You won't be eaten!\n");
		else printf("Uh oh..\n");
	}


	return 0;
}

