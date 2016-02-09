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

int Board[6][6], Row[10], Col[10], D1[10], D2[10];

int main () {
	for (int i=0; i<5; ++i) 
		for (int j=0; j<5; ++j)
			scanf("%d", &Board[i][j]);

	int x;
	for (int num=1; num<=25; ++num) {
		scanf("%d", &x);
		for (int i=0; i<5; ++i)
			for (int j=0; j<5; ++j) {
				if (Board[i][j] == x) 
					++Row[i], ++Col[j], ++D1[i-j+4], ++D2[i+j];
			}

		int cur = 0;
		if (num >= 10) {
			for (int i=0; i<10; ++i) {
				if (Row[i] == 5)
					++cur;
				if (Col[i] == 5)
					++cur;
				if (D1[i] == 5)
					++cur;
				if (D2[i] == 5)
					++cur;
			}
		}

		if (cur >= 3){
			cout << num << endl;
			break;
		}


	}

				
				






	return 0;
}

