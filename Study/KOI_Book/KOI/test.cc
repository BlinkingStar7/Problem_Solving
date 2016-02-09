#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	cout << a.size();
	cout << a.empty();
	a.push_back(2);
	cout << a.size();
	cout << a.empty();
	return 0;
}

