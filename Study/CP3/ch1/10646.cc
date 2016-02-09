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

string NUM = "123456789TJQKA";
inline int findVal(char c) {
	int ret = find(NUM.begin(), NUM.end(), c) - NUM.begin() + 1;
	return ret > 9 ? 10 : ret;
}

int main () {
	int t;
	cin >> t;
	for(int cnt=1; cnt<=t; ++cnt) {
		vector<string> card(52);
		for (int i=0; i<52; ++i)
			cin >> card[i];
		int y=0, cur=26;
		for (int i=0; i<3; ++i) {
			int x=findVal(card[cur][0]);
			y += x;
			cur -= 11-x;
		}
		card.erase(card.begin()+cur+1, card.begin()+27);
		printf("Case %d: %s\n", cnt, card[y-1].c_str());
	}

	return 0;
}

