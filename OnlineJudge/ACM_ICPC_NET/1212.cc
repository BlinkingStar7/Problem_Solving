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

const char to2[9][4] = {"", "1", "10", "11", "100","101", "110", "111"};
int main () {
	string input;
	cin >> input;
	
	if (input == "0") {
		putchar('0');
		return 0;
	}

	printf("%s", to2[input[0]-'0']);
	for (int i=1; i<input.size(); ++i) {
		for (int j=0; j<3-strlen(to2[input[i]-'0']); ++j)
			putchar('0');
		printf("%s", to2[input[i]-'0']);
	}



	return 0;
}

