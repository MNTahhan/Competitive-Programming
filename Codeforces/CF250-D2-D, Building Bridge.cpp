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

double dist(int x,int y,int a,int b){
    return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}
int n,m,a,b,A[100010],B[100010],l[100010];
double len[100010];

int main() {
#if !ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
    //freopen("b.txt", "w", stdout);
    decTime;
#endif
    
    scanf("%d%d%d%d",&n,&m,&a,&b);
     int idx1,idx2;
     double mn1=1e9,mn2=1e9;
    for(int i=0;i<n;++i){
        scanf("%d",A+i);
        len[i]=dist(0,0,a,A[i]);
        if(len[i]<mn1){
            mn1=len[i];
            idx1=i;
        }
    }
    for(int i=0;i<m;++i)
        scanf("%d",B+i);
    for(int i=0;i<m;++i){
        scanf("%d",l+i);
        if(l[i]<mn2){
            mn2=l[i];
            idx2=i;
        }
    }
    double ansLen=mn1+mn2+dist(a,A[idx1],b,B[idx2]);
    for(int i=0;i<m;++i){
        int lo=0,hi=n-1,idx=-1;
        while(lo<=hi){
            int mid1=lo+(hi-lo)/3;
            int mid2=hi-(hi-lo)/3;
            double newLen1=len[mid1]+l[i]+dist(a,A[mid1],b,B[i]);
            double newLen2=len[mid2]+l[i]+dist(a,A[mid2],b,B[i]);
            if(newLen1<newLen2){
                hi=mid2-1;
                idx=mid1;
            }else{
                lo=mid1+1;
                idx=mid2;
            }
        }
        if(idx==-1) continue;
        int newLen=len[idx]+l[i]+dist(a,A[idx],b,B[i]);
        if(newLen<ansLen){
            ansLen=newLen;
            idx1=idx;
            idx2=i;
        }
    }
    printf("%d %d\n",idx1+1,idx2+1);
    

#if !ONLINE_JUDGE
    printTime;
#endif
    return 0;
}
