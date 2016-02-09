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

int N;
string Name[51];
int main () {
	cin >> N;
	for (int i=0; i<N; ++i)
		cin >> Name[i];

	int num=0;
	for (int i=0; i<Name[0].size(); ++i) {
		int flag = 1;
		for (int j=1; j<N; ++j)
			if (Name[j][i] != Name[0][i]) {
				flag = 0;
				printf("?");
				break;
			}
		if (flag)
			printf("%c",Name[0][i]);
	}
	return 0;
}

