#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	int h=1;
	while(scanf("%lld",&n)>0 && n){
		ll ans=0,i,l,r;
		for(i=2;i*i<n;++i){
			ans+=i*(n/i-1);
			l=n/(i+1);
			r=n/i;
			if(l>=i)
				ans+=(i-1)*(r*(r+1)/2-l*(l+1)/2);
		}
		if(i*i==n) 
			ans+=i*(n/i-1);
		printf("Case %d: %lld\n",h++,ans);
	}
	return 0;
}
