#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int tN;
	cin >> tN;

	while (--tN >= 0) {
		int M, N;
		cin >> M >> N;
		cout << 1 << endl;
		if (N == 1) {
			for (int i=0; i<M; ++i)
				printf("(%d,0)\n",i);
			continue;
		}
		if (M%2==0) {
			for (int i=0; i<M; ++i)
				for (int j=0; j<N; ++j)
					if (i%2==0)	printf("(%d,%d)\n",i, j);
					else printf("(%d,%d)\n",i,N-1-j);
			continue;
		}
		else {
			for (int i=0; i<M; ++i)
				for (int j=0; j<N-1; ++j)
					if (i%2==0)	printf("(%d,%d)\n",i, j);
					else printf("(%d,%d)\n",i,N-2-j);
			for (int i=M-1; i>=0; --i)
				printf("(%d,%d)\n",i,N-1);
continue;}
	}
	return 0;
}


