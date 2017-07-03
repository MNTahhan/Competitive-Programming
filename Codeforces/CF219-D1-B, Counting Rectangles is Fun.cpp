/*
  The idea: consider the rectangle from every point to the end of the big rectangle, calc the cumulative sum of rectangles in this
            rectangle, then in every query loop on the points inside the query and add the number of rectangles from current point to 
            the end of query rectangle.
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,cum[44][44],dp[44][44][44][44];
char s[44][44];
int main() {
	int q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
		cum[i][j]=(s[i][j]=='1')+cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1];
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	for(int x=i;x<=n;++x)
	for(int y=j;y<=m;++y){
		if(cum[x][y]-cum[x][j-1]-cum[i-1][y]+cum[i-1][j-1]==0)
			++dp[i][j][x][y];
		dp[i][j][x][y]+=dp[i][j][x-1][y]+dp[i][j][x][y-1]-dp[i][j][x-1][y-1];	
	}
	while(q--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int ans=0;
		for(int i=a;i<=c;++i)
		for(int j=b;j<=d;++j)
			ans+=dp[i][j][c][d];
		printf("%d\n",ans);
	}
	return 0;
}
