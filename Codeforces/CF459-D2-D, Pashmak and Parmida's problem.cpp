#include<bits/stdc++.h>
using namespace std;
int BIT[1000010],nxt[1000010],cnt[1000010],n,a[1000010];
vector<int>v;
void add(int idx,int val){
	while(idx<1000010){
		BIT[idx]+=val;
		idx+=idx&-idx;
	}
}
int get(int idx){
	int res=0;
	while(idx){
		res+=BIT[idx];
		idx-=idx&-idx;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=0;i<n;++i)
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin();
	for(int i=n-1;i>=0;--i){
		++cnt[a[i]];
		nxt[i]=cnt[a[i]];
		add(nxt[i],1);
	}
	memset(cnt,0,sizeof cnt);
	long long ans=0;
	for(int i=0;i<n;++i){
		++cnt[a[i]];
		add(nxt[i],-1);
		ans+=get(cnt[a[i]]-1);
	}
	printf("%lld",ans);
	return 0;
}
