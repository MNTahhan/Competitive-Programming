#include <iostream>	
#include <time.h>
#include <vector>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <map>
#include <algorithm>
#include <bitset>
#include <queue>
#include <set>
#include <time.h>
#include <assert.h>
#include <sstream>
//#include <unordered_map>
#include <bitset>
#include <utility>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <math.h>
#include <string.h>
#include <string>
#include <complex>
#include <valarray>
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

int n,L[100010*4],R[100010*4],cnt[100010];
void update(int n,int s,int e,int at,int val,int *seg){
    if(s>at || e<at)
        return;
    if(s==e){
        seg[n]+=val;
        return;
    }
    update(n*2,s,(s+e)/2,at,val,seg);
    update(n*2+1,(s+e)/2+1,e,at,val,seg);
    seg[n]=seg[n*2]+seg[n*2+1];
}
int get(int n,int s,int e,int l,int r,int *seg){
    if(s>r || e<l)
        return 0;
    if(s>=l && e<=r)
        return seg[n];
    return get(n*2,s,(s+e)/2,l,r,seg)+get(n*2+1,(s+e)/2+1,e,l,r,seg);
}

int main() {
#if !ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
    //freopen("b.txt", "w", stdout);
    decTime;
#endif
    
    int t;
    scanf("%d",&t);
    int n=100002;
    while(t--){
        int l,r;
        scanf("%d%d",&l,&r);
        int res1=get(1,1,n,1,l-1,L)-get(1,1,n,1,l,R)-cnt[l];
        int res2=get(1,1,n,1,r-1,L)-get(1,1,n,1,r,R)-cnt[r];
        res1=max(res1,0);
        res2=max(res2,0);
        int ans=res1+res2;
        printf("%d\n",ans);
        cnt[l]+=res1;
        cnt[r]+=res2;
        update(1,1,n,l,1,L);
        update(1,1,n,r,1,R);
    }

    

#if !ONLINE_JUDGE
    printTime;
#endif
    return 0;
}
