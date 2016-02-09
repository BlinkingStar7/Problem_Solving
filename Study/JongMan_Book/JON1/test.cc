#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {


	vector<int> v{1, 3, 2, 1,2,2,4,2,3};
	for (int i=0; i<v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i=0; i<v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	return 0;
}


