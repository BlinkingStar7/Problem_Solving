#include <stdio.h>
 
int n,s;
int len[110];
int arr[110][1010];
int PI1[1010],PI2[1010];
 
bool pos(int st,int ed);
 
int main()
{
	 
	    scanf("%d %d",&n,&s);
		 
		    int i,j;
			 
			    for(i = 1;i <= n;i++)
					    {
							        scanf("%d",&len[i]);
									 
									        for(j = 1;j <= len[i];j++)
												            scanf("%d",&arr[i][j]);
											    }
				 
				    for(i = 1;i <= len[1] - s + 1;i++)
						    {
								        if(pos(i,i + s - 1) == true)
											        {
														            printf("YES");
																	            return 0;
																				        }
										    }
					    printf("NO");
						    return 0;
}
bool pos(int st,int ed)
{
	    int i,j,k;
		 
		    for(i = 1;i <= s;i++) PI1[i] = 0,PI2[i] = 0;
			 
			    PI1[1] = 0,PI2[1] = 0;
				 
				    for(i = 2;i <= s;i++)
						    {
								        j = PI1[i - 1] + 1;
										 
										        while(j != 1 && arr[1][st + j - 1] != arr[1][st + i - 1])
													            j = PI1[j - 1] + 1;
												 
												        if(arr[1][st + j - 1] == arr[1][st + i - 1]) PI1[i] = j;
														        else PI1[i] = 0;
																    }
					    for(i = 2;i <= s;i++)
							    {
									        j = PI2[i - 1] + 1;
											 
											        while(j != 1 && arr[1][ed - j + 1] != arr[1][ed - j + 1])
														            j = PI2[j - 1] + 1;
													 
													        if(arr[1][ed - j + 1] == arr[1][ed - i + 1]) PI2[i] = j;
															        else PI2[i] = 0;
																	    }
						 
						    for(i = 2;i <= n;i++)
								    {
										        k = 0;
												        for(j = 1;j <= len[i];j++)
															        {
																		            k++;
																					 
																					            if(k > s)
																									                break;
																								 
																								            while(k != 1 && arr[1][st + k - 1] != arr[i][j])
																												                k = PI1[k - 1] + 1;
																											 
																											            if(arr[1][st + k - 1] != arr[i][j]) k = 0;
																														        }
														        if(k != s && j > len[i])
																	        {
																				            k = 0;
																							            for(j = 1;j <= len[i];j++)
																											            {
																															                k++;
																																			 
																																			                if(k > s)
																																								                    break;
																																							 
																																							                while(k != 1 && arr[1][ed - k + 1] != arr[i][j])
																																												                    k = PI2[k - 1] + 1;
																																											 
																																											                if(arr[1][ed - k + 1] != arr[i][j]) k = 0;
																																															            }
																										            if(k != s && j > len[i])
																														            {
																																		                return false;
																																						            }
																													        }
																    }
							 
							    return true;
}
