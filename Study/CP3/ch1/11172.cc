#include <cstdio>
using namespace std;

int main() {
	int a, b, n;
	scanf("%d",&n);
	while(n--) {
		scanf("%d%d",&a,&b);
		printf("%c\n", a > b ? '>' : a == b ? '=' : '<');
	}
	return 0;
}
