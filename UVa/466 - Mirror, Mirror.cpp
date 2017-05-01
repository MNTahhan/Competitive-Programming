#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<complex>
#include<cmath>
#include<string.h>
#include<string>
#if !ONLINE_JUDGE
#include "inc.h"
#endif 
using namespace std;

vector<string>v,r;
char s[22];
int n;
void rotate90(){
	vector<string>tmp(r.size());
	for(int i=0;i<n;++i)
		tmp[i]=string(n,'\0');
	for(int i=0,b=n-1;i<n;++i,--b)
		for(int j=0,a=0;j<n;++j,++a)
			tmp[a][b]=v[i][j];
	tmp.swap(v);
}
void reflect(){
	vector<string>tmp(r.size());
	for(int i=0;i<n;++i)
		tmp[i]=string(n,'\0');
	for(int i=0,a=n-1;i<n;++i,--a)
		for(int j=0,b=0;j<n;++j,++b)
			tmp[a][b]=v[i][j];
	tmp.swap(v);
}

int main(){
#if !ONLINE_JUDGE
	freopen("a.txt","r",stdin);
#endif

	int h=1;
	while(scanf("%d",&n)>0){
		v.clear();
		r.clear();
		v.resize(n);
		r.resize(n);
		for(int i=0;i<n;++i){
			scanf("%s",s);
			v[i]=s;
			scanf("%s",s);
			r[i]=s;
		}
		printf("Pattern %d was ",h++);
		if(v==r){
			puts("preserved.");
			continue;
		}
		rotate90();
		if(v==r){
			puts("rotated 90 degrees.");
			continue;
		}
		rotate90();
		if(v==r){
			puts("rotated 180 degrees.");
			continue;
		}
		rotate90();
		if(v==r){
			puts("rotated 270 degrees.");
			continue;
		}
		rotate90();
		reflect();
		if(v==r){
			puts("reflected vertically.");
			continue;
		}
		rotate90();
		if(v==r){
			puts("reflected vertically and rotated 90 degrees.");
			continue;
		}
		rotate90();
		if(v==r){
			puts("reflected vertically and rotated 180 degrees.");
			continue;
		}
		rotate90();
		if(v==r){
			puts("reflected vertically and rotated 270 degrees.");
			continue;
		}
		puts("improperly transformed.");
	}

	
	return 0;
}
