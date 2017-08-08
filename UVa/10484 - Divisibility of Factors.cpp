/*
  The idea: all the prime factors of D must be factors of N!, and D primes powers must be less than or equal N! primes powers, to get 
            N! primes, add the powers of factors of numbers from 1 to N.
*/
#include <bits/stdc++.h>
using namespace std;
int n,d,cnt[110];
int main() {
	while(scanf("%d%d",&n,&d)>0 && d){
		d = abs(d);
		memset(cnt,0,sizeof cnt);
		for(int i=2;i<=n;++i){
			int x=i;
			for(int j=2;j<=x;++j){
				while(x%j==0){
					x/=j;
					++cnt[j];
				}
			}
		}
		int flag=1;
		for(int i=2;i<=100 && flag;++i){
			while(flag && d%i==0){
				if(cnt[i]==0) flag=0;
				d/=i;
				--cnt[i];
			}
		}
		if(d!=1 && (d>100 || !cnt[d]))
				flag=0;
			else if(d!=1)
				--cnt[d];
		long long ans=flag;
		for(int i=0;i<=n;++i)
			ans*=cnt[i]+1;
		printf("%lld\n",ans);
	}
	return 0;
}
