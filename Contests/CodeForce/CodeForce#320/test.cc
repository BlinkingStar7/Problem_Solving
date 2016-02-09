#include <iostream>
using namespace std;

int Solve(int n) {
	cout << n << endl;
	int ret = 0;
	ret =Solve(n-1);
}
int main() {
	Solve(200000);
	return 0;
}

