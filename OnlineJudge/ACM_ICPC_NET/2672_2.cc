#include<cstdio>
#include<algorithm>
#define dd double
 
struct box {
	    dd x1, x2, y1, y2;
		    box(){}
			    box(dd a, dd b, dd c, dd d) { x1=a, y1=b, x2=c, y2=d; }
};
int N, n;
 
bool Inter (box a, box b) { return a.x2 > b.x1 && a.x1 < b.x2 && a.y2 > b.y1 && a.y1 < b.y2; }
 
int main() {
	    box z[33];
		    dd x[66], y[66], ans=0;
			    scanf ("%d", &N);
				    for (int i=0; i<N; i++) {
						        scanf ("%lf%lf%lf%lf", &z[i].x1, &z[i].y1, &z[i].x2, &z[i].y2);
								        x[n] = z[i].x2 += z[i].x1;
										        y[n++] = z[i].y2 += z[i].y1;
												        x[n] = z[i].x1;
														        y[n++] = z[i].y1;
																    }
					    std::sort (x, x+n);
						    std::sort (y, y+n);
							    for (int i=0; i<n-1; i++) {
									        for (int j=0; j<n-1; j++) for (int k=0; k<N; k++)
												            if (Inter (box(x[i], y[j], x[i+1], y[j+1]), z[k])) {
																                ans += (x[i+1] - x[i]) * (y[j+1] - y[j]);
																				                break;
																								            }
											    }
								    if (ans - (long long)ans <= 1e-3) printf ("%.lf\n", ans);
									    else printf ("%.2lf\n", ans);
										    return 0;
}
