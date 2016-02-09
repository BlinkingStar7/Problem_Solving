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

struct Node {
	double price;
	int num;
	char name[100];
} A[1000001];

bool comp (const Node& a, const Node& b) {
	return a.num != b.num ? a.num > b.num : a.price < b.price;
}
int main () {
	int cnt = 1;
	while(1) {
		int n, p;
		char temp[100];
		scanf("%d%d\n", &n,&p);
		if (n == 0) break;
		getchar();
		for (int i=0; i<n; ++i)
			gets(temp);

		for (int i=0; i<p; ++i) {
			gets(A[i].name);
			scanf("%lf%d", &A[i].price, &A[i].num);
			getchar();
			for (int j=0; j<A[i].num; ++j)
				gets(temp);
		}

		sort(A, A+n, comp);
		if (cnt != 1) puts("");
		printf("RFP #%d\n%s\n", cnt++, A[0].name);
	}
	return 0;
}

