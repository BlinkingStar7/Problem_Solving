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

int Dice[14][6], Memo[1<<13][10000];
const int MIN = -987654321;

int getScore (int round, int index) {
	int sum = 0, Max = 0, Min = 6;
	for (int i=0; i<6; ++i) {
		sum += Dice[index][i]*(i+1);
		Max = max (Max, Dice[index][i]);
		Min = min (Min, Dice[index][i] == 0 ? Min : Dice[index][i]);
	}

	if (round < 6) {
		return Dice[index][round]*(round+1);
	}
	else if (round == 6) {
		return sum;
	}
	else if (round <= 9) {
		if (round == 7) return (Max >= 3) ? sum : 0;
		if (round == 8) return (Max >= 4) ? sum : 0;
		else return (Max >= 5) ? 50 : 0;
	}
	else if (round <= 11) {
		for (int start = 0; start < (round == 10 ? 3 : 2); ++start) {
			bool flag = true;
			for (int num = 0; num < (round == 10 ? 4 : 5); ++num) {
				if (Dice[index][start+num] == 0) {
					flag = false;
					 break;
				}
			}
			if (flag) {
				return (round == 10) ? 25 : 35;
			}
		}
		return 0;
	}
	else {
		return (Min == 2 && Max == 3) ? 40 : 0;
	}
	return MIN;
}

int Solve (int selected, int score) {
	if (selected == (1<<13)-1)
		return score >= 63 ? 35 : 0;

	int &ret = Memo[selected][score];
	if (ret != -1) return ret;

	ret = 0;
	
	for (int next=0; next<13; ++next) {
		if (!(selected & (1<<next))) {
			int s = getScore(next, __builtin_popcount(selected));  
			ret = max (ret, s + Solve(selected|(1<<next), score + (next < 6 ? s : 0)));
		}
	}

	return ret;
}

void reconstruct (vector<int>& ans, int selected, int score, int num) {
	if (num == 13) return;
	for (int i=0; i<13; ++i) {
		if ((selected & (1<<i)) == 0) {
			int s = getScore(i, num);
			if (Solve(selected, score) == Solve(selected | (1<<i),score+s) + s) {
				ans[i] = s;
				return reconstruct (ans, selected|(1<<i), score+s, num+1);
			}
		}
	}
}

int main () {
	while (1) {
		memset(Dice, 0, sizeof(Dice));
		memset(Memo, -1, sizeof(Memo));

		bool flag = false;
		for (int i=0; i<13; ++i) {
			for (int j=0; j<5; ++j) {
				int temp;
				if (scanf("%d", &temp) == EOF) {
					flag = true;
					break;
				}
				Dice[i][temp-1]++;
			}
			if (flag) break;
		}
		if (flag) break;
	
		int ret = Solve (0, 0);
		vector<int> ans(13);
		reconstruct (ans, 0, ret, 0);
		for (int i=0; i<ans.size(); ++i)
			printf("%d ", ans[i]);

		int sum=0;
		for (int i=0; i<13; ++i) {
			sum += ans[i];
			if (i == 5) {
				printf("%d ", (sum >=63 ? 35 : 0));
				sum += (sum >= 63 ? 35 : 0);
			}
		}
		printf("%d\n", sum);
	}



	return 0;
}

