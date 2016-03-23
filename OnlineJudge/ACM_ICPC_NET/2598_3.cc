#include <fstream>
using namespace std;
#define INFILE "input.txt"
#define OUTFILE "output.txt"
#define code_length 17
char cube[4][6], code[18], save[1000][18];
int pattern[6][6] = {{4, 5, 0, 1, 2, 3}, {5, 4, 0, 3, 2, 1}, {0, 2, 1, 4, 3, 5}, {2, 0, 1, 5, 3, 4},{1, 3, 0, 5, 2, 4}, {3, 1,
0, 4, 2, 5}};
int m;
void swap(char &a, char &b)
{
char c = a;
a = b, b = c;
};
void input()
{
char s[100];
for (int i=0;i<4;i++)
{
gets(s);
for (int j=0;j<6;j++)
cube[i][j] = s[j];
}
}
void code_shift()
{
for (int i=0;i<4;i++)
{
swap(code[i * 4 + 0], code[i * 4 + 1]);
swap(code[i * 4 + 1], code[i * 4 + 2]);
swap(code[i * 4 + 2], code[i * 4 + 3]);
}
}
void code_check()
{
int i, sw, same = 0;
for (i=0;i<4;i++)
{
if (same == 0)
for (int j=0;j<m;j++)
{
sw = 0;
for (int k=0;k<code_length;k++)
if (code[k] != save[j][k]) sw = 1;
if (sw == 0) same = 1;
}
code_shift();
}
if (same == 0)
{
for (i=0;i<code_length;i++)
save[m][i] = code[i];
m++;
}
}
void process(int p)
{
int i, j, k;
for (i=0;i<4;i++)
for (j=0;j<p-1;j++)
if (code[(p - 1) * 4 + i] == code[j * 4 + i]) return;
if (p == 4)
code_check();
else
for (i=0;i<6;i++) // pattern
for (j=0;j<4;j++)
{
for (k=0;k<4;k++)
code[p * 4 + k] = cube[p][pattern[i][2 + (j + k) % 4]];
if (p == 3) code[16] = cube[p][pattern[i][0]];
process(p + 1);
if (cube[p][2] == cube[p][3] && cube[p][3] == cube[p][4] &&
cube[p][4] == cube[p][5]) break;
if (cube[p][2] == cube[p][4] && cube[p][3] == cube[p][5] &&
cube[p][2] != cube[p][3] && j == 1) break;
}
}
void output()
{
cout << m << endl;
}
void main()
{
input();
process(0);
output();
}
