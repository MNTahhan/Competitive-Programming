#include<stdio.h>
#include<vector>
#include<iostream>
#include<complex>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<string.h>
#include<string>
using namespace std;
typedef long long ll;

const int N = 3000 + 1;
char s[2][N];
int n,m,at;
string calc(int bit){
	vector<string>v;
	while(s[bit][at]=='0'){
		++at;
		v.push_back(calc(bit));
	}
	sort(v.begin(),v.end());
	string cur="(";
	for(int i=0;i<v.size();++i)
		cur+=v[i];
	cur+=")";
	++at;
	return cur;
}

int main(){
	freopen("a.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",s[0],s[1]);
		n=strlen(s[0]);
		m=strlen(s[1]);
		if(n!=m){
			puts("different");
			continue;
		}
		at=0;
		string a=calc(0);
		at=0;
		string b=calc(1);
		puts(a==b?"same":"different");
	}
	return 0;
}
