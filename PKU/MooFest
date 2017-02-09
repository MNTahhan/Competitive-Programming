#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
typedef long long ll;
const int N=20000;
int n;
ll seg[3][(N+10)*4];
vector<pair<int,int> >v;
void update(int n,int s,int e,int at,int val,ll *seg){
	if(s>at || e<at)
		return;
	if(s==e){
		seg[n]+=val;
		return;
	}
	update(n*2,s,(s+e)/2,at,val,seg);
	update(n*2+1,(s+e)/2+1,e,at,val,seg);
	seg[n]=seg[n*2]+seg[n*2+1];
}
ll get(int n,int s,int e,int l,int r,ll *seg){
	if(s>r || e<l)
		return 0;
	if(s>=l && e<=r)
		return seg[n];
	return get(n*2,s,(s+e)/2,l,r,seg)+get(n*2+1,(s+e)/2+1,e,l,r,seg);
}
#define x second
#define y first
int main(){
	scanf("%d",&n);
	v=vector<pair<int,int> >(n);
	for(int i=0;i<n;++i)
		scanf("%d%d",&v[i].first,&v[i].second);
	sort(v.begin(),v.end());
	update(1,1,N,v[0].x,1,seg[0]);
	update(1,1,N,v[0].x,v[0].x,seg[1]);
	update(1,1,N,N-v[0].x,N-v[0].x,seg[2]);
	ll ans=0;
	for(int i=1;i<n;++i){
		int cntBefore=get(1,1,N,1,v[i].x,seg[0]);
		ll sumBefore=get(1,1,N,1,v[i].x,seg[1]);
		ll resBefore=cntBefore*1LL*v[i].x-sumBefore;
		int cntAfter=get(1,1,N,v[i].x,N+1,seg[0]);
		ll sumAfter=get(1,1,N,1,N-v[i].x,seg[2]);
		ll resAfter=cntAfter*1LL*(N-v[i].x)-sumAfter;
		ans+=v[i].y*1LL*(resBefore+resAfter);
		update(1,1,N,v[i].x,1,seg[0]);
		update(1,1,N,v[i].x,v[i].x,seg[1]);
		update(1,1,N,N-v[i].x,N-v[i].x,seg[2]);
	}
	cout<<ans<<endl;
	return 0;
}
