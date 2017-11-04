#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a,int b){
  if(!b)
    return a;
  return gcd(b,a%b);
}
int lcm(int a,int b){
  return a/gcd(a,b)*b;
}
int main(){
  int n;
  while(scanf("%d",&n)>0 && n){
    vector<int>v;
    for(int i=1;i*1LL*i<=n;++i)
      if(n%i==0){
        v.push_back(i);
        if(i!=n/i)
          v.push_back(n/i);
      }
    int ans=0;
    for(int i=0;i<v.size();++i)
      for(int j=i;j<v.size();++j)
        ans+=lcm(v[i],v[j])==n;
    printf("%d %d\n",n,ans);
  }
  return 0;
}


