#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<string>
#include<algorithm>
#include<time.h>
#include<memory.h>
using namespace std;
typedef long long ll;
#define print(x) cout<<#x<<" = "<<(x)<<endl
const int N = 1e6 + 10;
int n;
ll a[N + N],seg[8*N];
void build(int n,int s,int e){
	if(s==e){
		seg[n]=a[s];
		return;
	}
	build(n*2,s,(s+e)/2);
	build(n*2+1,(s+e)/2+1,e);
	seg[n]=min(seg[n*2],seg[n*2+1]);
}
ll get(int n,int s,int e,int l,int r){
	if(s>r || e<l)
		return 1LL<<60;
	if(s>=l && e<=r)
		return seg[n];
	return min(get(n*2,s,(s+e)/2,l,r),get(n*2+1,(s+e)/2+1,e,l,r));
}
int main(){
	//freopen("a.txt","r",stdin);
	while(scanf("%d",&n)>0 && n){
		for(int i=1;i<=n;++i){
			scanf("%lld",a+i);
			a[i]+=a[i-1];
		}
		for(int i=n+1;i<=2*n;++i)
			// sum of the previous n-length interval
			a[i]=a[i-1]+a[i-n]-a[i-n-1];
		memset(seg,0x7f,sizeof 0x7f);
		build(1,1,2*n);
		int ans=n;
		for(int i=1;i<=n;++i){
			// x is the minimum number in the next n-length interval
			ll x = get(1,1,2*n,i,i+n-1);
			// x - a[i-1] is the sum of the interval
			if(x-a[i-1]<0)
				--ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
