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
	string s;
	cin >> s;
	int num = 10;

	for (int i=1; i<s.size(); ++i)
		if (s[i] == s[i-1]) num+=5;
		else num += 10;
	cout << num << endl;

	return 0;
}

