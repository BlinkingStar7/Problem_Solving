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


int main () {
	char input[1000001];
	gets(input);

	int num=0;
	char * tok = strtok(input, " ");
	while (tok != NULL) {
		tok = strtok(NULL, " ");
		++num;
	}
	cout << num << endl;
	return 0;
}

