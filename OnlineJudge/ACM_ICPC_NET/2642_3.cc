#include<stdio.h>
#define Swap(aa,bb) {cc=aa;aa=bb;bb=cc;}
int a[6][6], b[7], c[7], d[7], cc;
int Match(int x1, int y1, int x2, int y2)
{
	int l1;
	if(x1 > x2) Swap(x1, x2);
	if(y1 > y2) Swap(y1, y2);
	if(x2 == x1 + 2)
	{
		for(l1=y1;l1<=y2;l1++)
			if(a[x1+1][l1] == 0) break;
				if(l1 > y2) return 1;
	}
	if(y2 == y1 + 2)
	{
		for(l1=x1;l1<=x2;l1++)
			if(a[l1][y1+1] == 0) break;
				if(l1 > x2) return 1;
	}
	return 0;
}
int main(void)
{
	int l1, l2, l3;
	for(l1=0;l1<6;l1++) for(l2=0;l2<6;l2++)
	{
		scanf("%d",&a[l1][l2]);
		b[a[l1][l2]]=l1;
		c[a[l1][l2]]=l2;
	}
	for(l1=1;l1<=6;l1++)
		if(d[l1] == 0)
			for(l2=l1+1;l2<=6;l2++)
				if(d[l2] == 0)
					if(Match(b[l1], c[l1], b[l2], c[l2]))
					{
						d[l1] = l2;
						d[l2] = l1;
						break;
					}
	for(l1=1;l1<=6;l1++) if(d[l1] == 0) break;
		if(l1 > 6) printf("%d\n",d[1]);
		else printf("0\n");
	return 0;
}
