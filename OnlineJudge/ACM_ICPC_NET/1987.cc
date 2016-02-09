#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	int tN;
	cin >> tN;
	int Num = 0;
	int flag = 1;
	while (--tN >= 0) {
		int N;
		flag = 1;
		cin >> N;

		if (N==1) continue;

		for (int x=2; x<=int(sqrt(N)); ++x)
			if (N%x == 0) {
				flag = 0;
				break;
			}
		Num += flag;
	}
	cout << Num << endl;

	return 0;
}


