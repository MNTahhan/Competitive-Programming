/*
	
	The idea is straigt forward, try to put the first card in the second 
	position, then put the second card two positions away from it, then 
	put the third card three positions away from the second card and so on.. 
	if you reach the end of the array continue counting from the begenning (only
	count the empty places)
	to make the solution faster, skip the adjacent non-empty places by 
	connecting them as one component (make disjoint sets)

*/


#include <bits/stdc++.h>
using namespace std;
const int N = 20000 + 10;
int n,p[N];
int find(int x){
	if(p[x]==x)
		return x;
	return p[x]=find(p[x]);
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		vector<int>v(n);
		for(int i=0;i<=n;++i)
			p[i]=i;
		p[n]=0;
		int last=0,cur=0,ans=1;
		for(int k=0;k<n;++k){
			int i,j;
			for(i=find(last+1),j=0;j<cur;i=find(i+1),++j);
			if(ans>1)
				i=find(i+1);
			v[i]=ans++;
			p[i]=find(p[i+1]);
			cur=(cur+1)%n; // every n moves returns the deck the its initial state
			last=i;
		}
		printf("%d",v[0]);
		for(int i=1;i<n;++i)
			printf(" %d",v[i]);
		puts("");
	}
	return 0;
}
