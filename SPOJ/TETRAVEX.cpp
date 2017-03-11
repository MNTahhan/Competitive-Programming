#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,r,d,l;
	node(){}
	node(int u,int r,int d,int l):u(u),r(r),d(d),l(l){}
};
vector<node>v;
vector<int>ans;
int msk;
int calc(int at){
	if(at==9)
		return ans.size()==9;
	for(int i=0;i<9;++i)
		if(!((msk>>i)&1)){
			if(!at);
			else if(at<3){
				if(v[i].l!=v[ans.back()].r)
					continue;
			}else if(at<6){
				if(v[i].u != v[ans[ans.size()-3]].d)
					continue;
				if(at>3 && v[i].l != v[ans.back()].r)
					continue;
			}else{
				if(v[i].u != v[ans[ans.size()-3]].d)
					continue;
				if(at>6 && v[i].l != v[ans.back()].r)
					continue;
			}
			msk|=1<<i;
			ans.push_back(i);
			if(calc(at+1))
				return 1;
			ans.pop_back();
			msk&=~(1<<i);
		}
	return 0;
}
int main() {
	int t;
	scanf("%d",&t);
	int h=1;
	while(t--){
		v.clear();
		for(int i=0,a,b,c,d;i<9;++i){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			v.push_back(node(a,b,c,d));
		}
		ans.clear();
		msk=0;
		printf("Case %d: %s\n",h++,calc(0)?"YES":"NO");
		if(t)
			puts("");
	}
	return 0;
}
