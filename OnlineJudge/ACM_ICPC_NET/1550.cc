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
	int num=0, base = 1; 
	for (int i=s.size()-1; i>=0; --i, base*=16) {
		if (isdigit(s[i])) num += base*(s[i]-'0');
		else num += base*(10+s[i]-'A');
	}
	cout << num << endl;

	return 0;
}

