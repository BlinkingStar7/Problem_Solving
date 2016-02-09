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
#define IFN 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) do {} while (false)
#endif

string bend[6][6] = {{}, {}, 
	{"+y", "-y", "-x", "+x", "+z", "-z"},
	{"-y", "+y", "+x", "-x", "+z", "-z"},
	{"+z", "-z", "+y", "-y", "-x", "+x"},
	{"-z", "+z", "+y", "-y", "+x", "-x"}};
int main () {
	map<string, int> m;
	m["+x"] = 0;
	m["-x"] = 1;
	m["+y"] = 2;
	m["-y"] = 3;
	m["+z"] = 4;
	m["-z"] = 5;
	while(1) {
		int n;
		scanf("%d", &n);
		if (!n) break;
		string cur = "+x";
		for (int i=0; i<n-1; ++i) {
			string temp;
			cin >> temp;
			if (temp == "No") continue;
			cur = bend[m[temp]][m[cur]];
		}
		cout << cur << endl;
	}
	return 0;
}

