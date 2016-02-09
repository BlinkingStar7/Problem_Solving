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
	int h, m, take;
	cin >> h >> m >> take;

	h += take/60;
	m += take%60;
	h += m/60;
	cout << h%24 << " " << m%60 << endl;


	return 0;
}

