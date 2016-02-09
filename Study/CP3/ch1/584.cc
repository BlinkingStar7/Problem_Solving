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
	char input[100];
	while(gets(input)) {
		if (input[0] == 'G') break;

		vector<int> score;
		int bef = 0;
		for (int i=0; i<strlen(input); ++i)
			if (input[i] == ' ') continue;
			else if (input[i] == 'X') score.push_back(10);
			else if (input[i] == '/') score.push_back(10-bef);
			else {
				score.push_back(input[i]-'0');
				bef = score.back();
			}

		vector<int> round(score.size(), 0);
		vector<bool> spare(score.size(), false), strike(score.size(), false);

		int r=1;
		for (int i=0; i<score.size(); ++i, ++r) {
			round[i] = r;
			if (r > 10) continue;
			if (score[i] == 10) strike[i] = true;
			else {
				round[i+1] = r;
				if (score[i] + score[i+1] == 10) spare[i+1] = true;
				++i;
			}
		}
		
		DPRINTF(("score : "));
		for (int i=0; i<score.size(); ++i) 
			DPRINTF((" %2d", score[i]));
		DPRINTF(("\n"));
		DPRINTF(("round : "));
		for (int i=0; i<round.size(); ++i)
			DPRINTF((" %2d", round[i]));
		DPRINTF(("\n"));
		DPRINTF(("strik : "));
		for (int i=0; i<strike.size(); ++i)
			DPRINTF(("  %c", strike[i] ? 'o' : ' '));
		DPRINTF(("\n"));
		DPRINTF(("spare : "));
		for (int i=0; i<round.size(); ++i)
			DPRINTF(("  %c", spare[i] ? 'o' : ' '));
		DPRINTF(("\n"));

		int ans = 0;
		for (int i=0; i<score.size(); ++i) {
			if (round[i] > 10) break;
			ans += score[i];
			if (strike[i]) ans += score[i+1] + score[i+2];
			if (spare[i]) ans += score[i+1];
		}

		cout << ans << endl;
	}
	return 0;
}

