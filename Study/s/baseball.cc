#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

#define MAX 10000

vi cand;
int ansOfComputer, ansOfUser;

bool isValid(int num) {
	int set = 0;
	for (int i=0; i<4; ++i, num/=10) {
		int cur = num%10;
		if (set & (1<<cur)) return false;
		set |= (1<<cur);
	}
	return true;
}

pii evaluate(int answer, int input) {
	vi a(10), b(10);
	for (int i=1; i<=4; ++i) {
		a[answer%10] = i; b[input%10] = i;
		answer/=10; input/=10;
	}
	int st=0,ba=0;
	for (int i=0; i<10; ++i)
		if (a[i] && b[i]) {
			if (a[i] == b[i]) ++st;
			else ++ ba;
		}
	return make_pair(st, ba);
}

void init() {
	printf("숫자 생각중...\n");
	printf("인공지능 초기화중...\n");
	cand.clear();
	srand(time(NULL));
	ansOfComputer = 0;
	while (!isValid(ansOfComputer)) ansOfComputer = rand()%MAX;
	for (int i=0; i<MAX; ++i) 
		if (isValid(i)) cand.push_back(i);
	DPRINTF(("ansOfComputer is %d\n", ansOfComputer));
	printf("준비완료!!!\n\n");
}

void playByComputer() {
	int cnt = 0;
	while (1) {
		int st, ba, guess = cand[rand()%(cand.size())];
		printf("당신이 생각한 숫자는 %d 입니까? 몇스트라이크 몇볼인지 입력해 주세요\n", guess);
		scanf("%d%d",&st,&ba);
		cnt++;
		if (st == 4) {
			printf("%d의 시도만에 컴퓨터가 숫자를 맞췄습니다!!!\n", cnt);
			return;
		}
		printf("\n");

		vi next;
		for (int i=0; i<cand.size(); ++i) {
			pii ret = evaluate(cand[i], guess);
			if (ret.first == st && ret.second == ba) next.push_back(cand[i]);
		}
		cand = next;
	}
}

void playByHuman() {
	int cnt = 0, input;
	while(1) {
		printf("예상한 숫자를 입력해 주세요 [0123 - 9876] :");
		scanf("%d", &input);
		if (!isValid(input)) {
			printf("입력 형식에 맞게 숫자를 입력해 주세요\n");
			continue;
		}
		
		++cnt;
		pii ret = evaluate(ansOfComputer, input);
		if (ret.first == 4) {
			printf("축하합니다!!! %d 번의 시도만에 숫자를 맞추셨습니다\n\n", cnt);
			return; 
		}

		printf("%d회 결과 : %d 스트라이크, %d 볼입니다.\n\n", cnt, ret.first, ret.second);
	}
}

int main () {

	while (1) {
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
		printf("    WELCOME TO NUMBER BASEBALL GAME!!!\n");
		printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
		printf("\n\n");

		init();

		int option; 
		while (1) {
			printf("컴퓨터가 생각한 숫자를 맞추려면 1, 당신이 생각한 숫자를 맞추려면 2를 입력하세요\n");
			scanf("%d", &option);
			if (option == 1 || option == 2) break;
			printf("잘못된 입력입니다.\n");
		}

		if (option == 1) playByHuman();
		else playByComputer();

		while (1) {
			printf("게임이 끝났습니다. 계속하시려면 1을 종료하려면 2를 입력하세요\n");
			scanf("%d", &option);
			if (option == 1 || option == 2) break;
			printf("잘못된 입력입니다.\n");
		}
		if (option == 2) break;
	}
	return 0;
}


