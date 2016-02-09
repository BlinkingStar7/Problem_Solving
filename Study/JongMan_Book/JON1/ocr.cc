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

int C, wordNum, senNum, input[101], N, bestChoice[501][101];
string Word[501];
double B[501], T[501][501], M[501][501], Memo[501][101];

void Input() {
	cin >> wordNum >> senNum;
	for (int i=0; i<wordNum; ++i)
		cin >> Word[i];

	for (int i=0; i<wordNum; ++i) {
		scanf("%lf", B+i);
		B[i] = log(B[i]);
	}

	for (int i=0; i<wordNum; ++i)
		for (int j=0; j<wordNum; ++j) {
			scanf("%lf", &T[i][j]);
			T[i][j] = log(T[i][j]);
		}

	for (int i=0; i<wordNum; ++i)
		for (int j=0; j<wordNum; ++j) {
			scanf("%lf", &M[i][j]);
			M[i][j] = log(M[i][j]);
		}
}

double Solve (int bef, int pos) {
	if (pos == N) return 0;

	double &ret = Memo[bef][pos];
	if (ret != 1) return ret;

	ret = -1e200;

	if (pos == 0) {
		for (int next = 0; next < wordNum; ++next){
			if (ret < B[next] + M[next][input[pos]] + Solve(next, pos+1)) {
				ret = B[next] + M[next][input[pos]] + Solve(next, pos+1);
				bestChoice [bef][pos] = next;
			}
		}
	}
	else {
		for (int next = 0; next < wordNum; ++next){
			if (ret < T[bef][next] + M[next][input[pos]] + Solve(next, pos+1)) {
				ret = T[bef][next] + M[next][input[pos]] + Solve(next, pos+1);
				bestChoice [bef][pos] = next;
			}

		}
	}
	return ret;
}

int main () {
	Input();

	for (int i=0; i<senNum; ++i) {
		cin >> N;
		for (int i=0; i<wordNum; ++i)
			for (int j=0; j<N; ++j)
				Memo[i][j] = 1;

		for (int j=0; j<N; ++j) {
			string temp;
			cin >> temp;
			for (int k=0; k<wordNum; ++k)
				if (temp == Word[k]) {
					input[j] = k;
					break;
				}
		}

		Solve (0, 0);

		int bef = 0;
		for (int k=0; k<N; ++k) {
			int next = bestChoice[bef][k];
			cout << Word[next] << " ";
			bef = next;
		}
		cout << endl;
	}



	return 0;
}

