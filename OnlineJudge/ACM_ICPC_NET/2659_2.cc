#include<stdio.h>
   
main()
{
	int N=0,i,j,k,l,w,x,y,z;
	int d[10][10][10][10]={{{{0,}}}};
	scanf("%d%d%d%d",&w,&x,&y,&z);
	d[w][x][y][z]=d[x][y][z][w]=d[y][z][w][x]=d[z][w][x][y]=2;
	for(i=1;i<10;i++)
	{
		for(j=1;j<10;j++)
		{
			for(k=1;k<10;k++)
			{
				for(l=1;l<10;l++)
				{
					if(!d[i][j][k][l])
					{
						N++;
						d[i][j][k][l]=1;
						d[j][k][l][i]=1;
						d[k][l][i][j]=1;
						d[l][i][j][k]=1;
					}
					else if(d[i][j][k][l]==2)goto end;
				}
			}
		}
	}
end:printf("%d",N+1);
}
