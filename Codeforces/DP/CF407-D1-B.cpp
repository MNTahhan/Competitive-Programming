// The idea: the same idea in this comment http://codeforces.com/blog/entry/11333?#comment-163547

#include <bits/stdc++.h>
using namespace std;
int n,p[1010];
long long dp[1010];
const int M = 1e9+7;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",p+i);
	for(int i=1;i<=n;++i){
		dp[i]=2;
		for(int j=p[i];j<i;++j)
			dp[i]=(dp[i]+dp[j])%M;
	}
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans=(ans+dp[i])%M;
	printf("%lld",ans);
	return 0;
}
