#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<time.h>
#include<cmath>
#include<math.h>
using namespace std;
typedef long long ll;
#define print(x) cout<<#x<<" = "<<x<<endl
int main(){
	freopen("a.txt","r",stdin);
	int n;
	while(scanf("%d",&n)>0 && n){
		int x = ceil(sqrt(n));
		ll line=x*1LL*x-(x-1);
		ll dif = max((ll)n,line) - min((ll)n,line);
		int y = x - dif;
		if((x&1) && n>line)
			swap(x,y);
		else if(!(x&1) && n<line)
			swap(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}
