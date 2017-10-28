#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
typedef vector<vector<int> > mat;
mat mul(const mat &a,const mat &b){
  mat ans=vector<vector<int> >(4,vector<int>(4));
  for(int i=0;i<4;++i)
  for(int j=0;j<4;++j)
  for(int k=0;k<4;++k)
    ans[i][j]=(ans[i][j]+a[i][k]*1LL*b[k][j])%M;
  return ans;
}
mat power(const mat &a,int p){
  if(p==1)
    return a;
  mat z=power(a,p>>1);
  z=mul(z,z);
  if(p&1)
    z=mul(z,a);
  return z;
}
int main(){
  mat v = vector<vector<int> >(4,vector<int>(4));
  for(int i=0;i<4;++i)
    for(int j=0;j<4;++j)
      if(i!=j)
        v[i][j]=1;
  int n;
  scanf("%d",&n);
  v=power(v,n);
  printf("%d\n",v[0][0]);
  return 0;
}
