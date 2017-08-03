/*
  The idea: similar to the repetion idea in the second KMP vedio
*/
#include <bits/stdc++.h>
using namespace std;
int f[1000010],n;
char s[1000010];
int main() {
	int t,h=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s);
		for(int i=1,k=0;i<n;++i){
			while(k && s[i]!=s[k])
				k=f[k-1];
			f[i]=(k+=(s[i]==s[k]));
		}
		printf("Test case #%d\n", h++);
		for(int i=1,k=0;i<n;++i)
			if(f[i] && (i+1)%(i-f[i]+1)==0)
				printf("%d %d\n",i+1,(i+1)/(i-f[i]+1));
		if(t)
			puts("");
	}
	return 0;
}

