#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int N;

int main () {

	cin >> N;
	cout << N;
	vector<int> left, right;
	for (int i=1; N > 0; i*=3, N/=3) {
		if (N % 3 == 1) right.push_back(i);
		else if (N % 3 == 2) {
			left.push_back(i);
			N += i;
		}
	}
	for (int i=0; i<left.size(); ++i)
		printf(" %d", left[i]);
	printf(" 0");
	for (int i=0; i<right.size(); ++i)
		printf(" %d", right[i]);
		
	return 0;
}

