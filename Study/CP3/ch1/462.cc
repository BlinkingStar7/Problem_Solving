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

string NUM = "123456789TJQKA", PAIR = "SHDC";
int c[300];
void init() {
	int cnt = 1;
	for (int i=0; i<NUM.size(); ++i)
		c[NUM[i]] = cnt++;
	cnt = 1;
	for (int i=0; i<PAIR.size(); ++i)
		c[PAIR[i]] = cnt++;
}

int main () {
	init();
	while(1) {
		int card[20][6], score[10];
		memset(card, 0, sizeof(card));
		memset(score, 0, sizeof(score));

		char input[10];
		for (int i=0; i<13; ++i) {
			if (scanf("%s", input) == EOF) return 0;
			card[c[input[0]]][c[input[1]]]++;
			card[c[input[0]]][5]++;
			card[15][c[input[1]]]++;
		}

		for (int i=0; i<4; ++i) {
			score[1] += card[11+i][5]*(i+1);
		}

		for (int i=0; i<3; ++i) {
			for (int pair=1; pair<=4; ++pair) {
				if (card[11+i][pair] && card[15][pair] <= 3-i)
					score[4-i]--;
			}
		}

		for (int pair=1; pair<=4; ++pair)
			if (card[15][pair] == 0) score[7]+=2;
			else if (card[15][pair] == 1) score[6]+=2;
			else if (card[15][pair] == 2) score[5]+=1;

		int stoped = 0;
		for(int pair=1; pair<=4; ++pair)
			if (card[14][pair] || (card[13][pair] && card[15][pair] >= 2) || (card[12][pair] && card[15][pair]>=3))
				++stoped;

		int sum=0, sum2=0;
		for (int i=1; i<=7; ++i) {
			DPRINTF(("score[%d] = %d\n", i, score[i]));
			sum+=score[i];
			if (i <=4 ) sum2+=score[i];
		}

		if (sum < 14) {
			cout << "PASS" << endl;
		}
		else if (sum2>=16 && stoped==4)
			cout << "BID NO-TRUMP" << endl;
		else {
			int best = 1;
			for (int i=1; i<=4; ++i) {
				if (card[15][i] > card[15][best])
					best = i;
			}
			cout << "BID " << PAIR[best-1] << endl;
		}
	}

	return 0;

}

