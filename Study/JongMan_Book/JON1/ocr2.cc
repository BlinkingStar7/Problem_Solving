#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;

int choice[102][102], C, Num, Q, Sentence[101], N;
string Word[501];
double B[501], T[501][501], M[501][501], Memo[501][102];

double Solve (int before, int cur) {
	if (cur == N) return 0.0;

	double &ret = Memo[before][cur];
	if (ret != 1.0) return ret;

	ret = -1e200;
	if (cur == 0)
		for (int cand=0; cand<Num; ++cand)
			ret = max (ret, B[cand] + M[cand][Sentence[cur]] + Solve(cand, cur+1));
	else
		for (int cand=0; cand<Num; ++cand)
			ret = max (ret, T[before][cand] + M[cand][Sentence[cur]] + Solve(cand, cur+1));

	return ret;
}
int main () {

	cin >> Num >> Q;


	for (int i=0; i<Num; ++i)
		cin >> Word[i];

	for (int i=0; i<Num; ++i) {
		double temp;
		scanf("%lf", &temp);
		B[i] = log(temp);
	}

	for (int i=0; i<Num; ++i)
		for (int j=0; j<Num; ++j) {
			double temp;
			scanf("%lf", &temp);
			T[i][j] = log(temp);
		}

	for (int i=0; i<Num; ++i)
		for (int j=0; j<Num; ++j) {
			double temp;
			scanf("%lf", &temp);
			M[i][j] = log(temp);
		}

	for (int i=0; i<Q; ++i) {
		cin >> N;
		for (int j=0; j<N; ++j) {
			string temp;
			cin >> temp;
			for (int k=0; k<Num; ++k)
				if (Word[k] == temp) {
					Sentence[j] = k;
					break;
				}
		}

		for (int bef=0; bef<Num; ++bef)
			for (int pos=0; pos<N; ++pos)
				Memo[bef][pos] = 1.0;

		Solve (0, 0);

	}





	return 0;
}

