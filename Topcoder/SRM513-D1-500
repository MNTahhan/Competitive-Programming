#include<bits/stdc++.h>
using namespace std;
double dp[2020][2020];
int vis[2020][2020];
double calc(int a,int b){
	if(a+b==0)
		return 0;
	if(!vis[a][b]){
		vis[a][b]=1;
		int t=2*a+b;
		double &ret=dp[a][b];
		ret=1;
		double p=1.0*b/(1.0*t);
		if(b)
			ret+=p*calc(a,b-1);
		if(a){
			ret+=(1.0-p)*(1.0/(t-1.0))*calc(a-1,b);
			if(a>1)
				ret+=(1.0-p)*((a*2.0-2)/(t-1.0))*calc(a-2,b+2);
			if(b)
				ret+=(1.0-p)*(1.0*b)/(1.0*t-1)*(1+calc(a-1,b));
		}
	}
	return dp[a][b];
}
class PerfectMemory{
public:
	double getExpectation(int N, int M){
		return calc(N*M/2,0);
	}
};
