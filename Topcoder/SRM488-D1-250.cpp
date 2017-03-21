#include<bits/stdc++.h>
using namespace std;
double dp[555][555];
int vis[555][555];
double calc(int n,int m){
	if(m<=0)
		return 0;
	double &ret=dp[n][m];
	int &vs=vis[n][m];
	if(vs)
		return ret;
	vs=1;
	ret=0;
	int t = n+m;
	double mm=(m*(m-1))/(t*(t-1.0));
	double nm=(n*m)/(t*(t-1)/2.0);
	ret=(1.0+mm*calc(n+2,m-2)+nm*calc(n+1,m-1))/(mm+nm);
	return ret;
}
class TheBoredomDivOne{
public:
	
	double find(int n, int m){
		return calc(n,m);
	}
};
