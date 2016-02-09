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

int main () {
	pair<int, int> A[3];

	int n, area = 0, b = -1;
	for (int i=0; i<3; ++i) {
		cin >> A[i].first >> A[i].second;
		area += A[i].first * A[i].second;
	}

	for (n=1; n*n<area; ++n);
	if (n*n != area) {
		printf("-1\n");
		return 0;
	}

	int num = 0;
	for (int i=0; i<3; ++i)
		if (A[i].first == n || A[i].second == n) {
			b = i;
			++num;
		}

	if (b == -1 || num == 2) {
		printf("-1\n");
		return 0;
	}
	if (num == 3) {
		cout << n << endl;
		for (int i=0; i<3; ++i) {
			string s = string (n,'A'+i);
			for (int j=0; j<min(A[i].first, A[i].second); ++j)
				cout << s << endl;
		}
		return 0;
	}


	int x, y, shrt = n - min (A[b].first, A[b].second);
	if (b == 0) x = 1, y = 2;
	else if(b == 1) x = 0, y = 2;
	else x = 0, y = 1;

	
	if (A[x].first != shrt) {
		int temp = A[x].second;
		A[x].second = A[x].first;
		A[x].first = temp;
	}
	if (A[y].first != shrt) {
		int temp = A[y].second;
		A[y].second = A[y].first;
		A[y].first = temp;
	}

	if (A[x].first != shrt || A[y].first != shrt) {
		printf("-1\n");
		return 0;
	}
	if (A[x].second + A[y].second != n) {
		printf("-1\n");
		return 0;
	}

	cout << n << endl;
	string s = string (n, 'A'+b);
	for (int i=0; i<min(A[b].first, A[b].second); ++i)
		cout << s << endl;

	string q = string (A[x].second, 'A'+x);
	string r = string (A[y].second, 'A'+y);

	for (int i=0; i<shrt; ++i)
		cout << q+r << endl;
	return 0;
}

