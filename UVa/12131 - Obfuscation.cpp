/*
	The idea: count the number of solutions with dp, and retrieve the solution backwards from dp array
*/
#include <bits/stdc++.h>
using namespace std;
struct node{
	int cnt,idx;
	node(){}
	node(int cnt,int idx):cnt(cnt),idx(idx){}
};
char s[1010],r[10010][110];
int dp[20010];
int argdp[20010][2];
int ans[20010];
int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		scanf("%d",&n);
		map<string,node>m;
		map<string,node>::iterator it;
		for(int i=0;i<n;++i){
			scanf("%s",r[i]);
			string tmp=r[i];
			sort(tmp.begin(),tmp.end());
			tmp+=r[i][0];
      tmp+=r[i][strlen(r[i])-1];
			it=m.find(tmp);
			if(it==m.end())
				m[tmp]=node(1,i);
			else
				m[tmp].cnt++;
		}
		int len=strlen(s);
		memset(dp,0,sizeof dp);
		memset(argdp,0,sizeof argdp);
		dp[0]=1;
		for(int i=0;i<len;++i)
			if(dp[i]) // the last word finished in the previous character
				for(int j=1;j<110 && i+j<=len;++j){
					char tmp=s[i+j];
					s[i+j]='\0';
					string cur=s+i;
					sort(cur.begin(),cur.end());
					cur+=s[i];
          cur+=s[i+j-1];
					it=m.find(cur);
					if(it!=m.end()){
						dp[i+j]+=dp[i]*(it->second.cnt); // dp[i]: solutions till now | it->second.cnt: number of words fits in the previous segment
						if(dp[i+j]>2) dp[i+j]=2;
						argdp[i+j][0]=i;
						argdp[i+j][1]=it->second.idx;
					}
					s[i+j]=tmp;
				}
		if(dp[len]==0)
			puts("impossible");
		else if(dp[len]>1)
			puts("ambiguous");
		else{
			int i=0;
			while(len){
				ans[i++]=argdp[len][1];
				len=argdp[len][0];
			}
			assert(i>0);
			printf("%s", r[ans[i-1]]);
			for(int j=i-2;j>=0;--j)
				printf(" %s",r[ans[j]]);
			puts("");
		}
	}
	return 0;
}
