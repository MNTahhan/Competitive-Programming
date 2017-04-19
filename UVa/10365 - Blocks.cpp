#include<iostream>
#include<string.h>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

int main(){
	freopen("a.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int ans=1<<30;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				for(int k=1;i*j<=n && i*j*k<=n && k<=n;++k)
					if(i*j*k==n)
						ans=min(ans,2*(i*j+i*k+j*k));
		printf("%d\n",ans);
	}
	return 0;
}
