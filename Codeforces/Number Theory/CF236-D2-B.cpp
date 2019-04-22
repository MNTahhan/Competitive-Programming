/*
  The idea: prime factorization, the number of divisors for any number is the the multiplication of powers of each prime factor + 1
  360 = 2^3 * 3^2 * 5, number of divisors of 360 = (3+1) * (2+1) * (1 + 1) = 24
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 110*110*110;
const int M = 1073741824;
int num[N],cnt[N];
vector<int>p;
int main() {
	for(int i=2;i*i<N;++i)
		if(!num[i])
			for(int j=i*i;j<N;j+=i)
				num[j]=1;
	for(int i=2;i<N;++i)
		if(!num[i])
			p.push_back(i);
	for(int i=1;i<N;++i){
		cnt[i]=1;
		int x=i,j=0;
		while(x>p[j] && num[x]){
			int c=0;
			while(x%p[j]==0){
				++c;
				x/=p[j];
			}
			++j;
			cnt[i]*=c+1;
		}
		if(x>1)
			cnt[i]*=2;
	}
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	long long ans = 0;
	for(int i=1;i<=a;++i)
	for(int j=1;j<=b;++j)
	for(int k=1;k<=c;++k)
		ans = (ans + cnt[i * j * k]) % M;
	printf("%lld\n",ans);
	return 0;
}
