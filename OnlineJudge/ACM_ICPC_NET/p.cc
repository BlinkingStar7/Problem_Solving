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

bool compare (int a, int b) {
	return a > b;
}

int main () {
	int arr[10] = {3, 2, 1, 5, 6, 3, 9, 5, 8};

	sort(arr, arr+10, less<int>());

	for (int i=0; i<10; ++i)
		printf("%d ", arr[i]);
	
	return 0;
}

