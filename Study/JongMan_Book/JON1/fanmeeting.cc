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

int fan[200001], mem[200001], ans[400001];

void Solve (int a1, int a2, int b1, int b2) {
	if (b1 == b2) {
		for (int i=a2; i<=a1; ++i)
			ans[i+b1-1] = fan[i] & mem[b1];
		return;
	}


					

int main () {
	int N;
	cin >> N;

	while (N--) {
		char ch;
		getchar();
		while ((ch = getchar()) != '\n')
			mem.push_back(ch == 'F' ? 1 : 0);
		while ((ch = getchar()) != '\n') 
			fan.push_back(ch == 'F' ? 1 : 0);

		reverse (mem.begin(), mem.end());


		

	return 0;
}

