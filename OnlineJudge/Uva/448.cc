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
#define MAX_N 123456789

char cmd[MAX_N];
unsigned long long charToHex[256];
const char OPCODE[4][10] = {"R", "$", "PC+", ""},
	  INSTRUCTION[16][5] = {
		  "ADD",
		  "SUB",
		  "MUL",
		  "DIV",
		  "MOV",
		  "BREQ",
		  "BRLE",
		  "BRLS",
		  "BRGE",
		  "BRGR",
		  "BRNE",
		  "BR",
		  "AND",
		  "OR",
		  "XOR",
		  "NOT"};
const int opNum[16] = {2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1};

inline unsigned long long getOpcode (unsigned long long hex) {
	return hex & 0xC000;
}

inline unsigned long long getOperand (unsigned long long hex) {
	return hex & 0x3FFF;
}

unsigned long long toHex(int pos, int num) {
	unsigned long long ret = 0;
	for (int i=0; i<num; ++i) {
		ret <<= 4;
		ret += charToHex[cmd[pos++]];
	}
	return ret;
}

int main () {
	int cnt = 0;
	for (char a='0'; a<='9'; ++a)
		charToHex[a] = cnt++;
	for (char a='A'; a<='F'; ++a)
		charToHex[a] = cnt++;

	int cur = 0;
	while (gets(&cmd[cur]) != NULL) {
		cur += 30;
	}

	int len = strlen(cmd);
	int pos = 0;

	while (pos < len) {
		unsigned long long instruction = charToHex[cmd[pos++]];
		printf("%s ", INSTRUCTION[instruction]);

		for (int i=0; i<opNum[instruction]; ++i) {
			unsigned long long operand = toHex(pos, 4);
			pos += 4;
			if (i) putchar(',');
			printf("%s%lld",OPCODE[getOpcode(operand)>>14], getOperand(operand));
		}
		putchar('\n');
	}
	return 0;
}

