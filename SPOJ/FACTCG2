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

int num[10000010],n;
vector<int>p;

int main() {
#if !ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
    //freopen("b.txt", "w", stdout);
    decTime;
#endif
    
    for(int i=2;i*1LL*i<10000010;++i)
        if(!num[i])
            for(int j=i*i;j<10000010;j+=i)
                num[j]=1;
    for(int i=2;i<10000010;++i)
        if(!num[i])
            p.push_back(i);
    num[1]=1;
    while(scanf("%d",&n)>0){
        printf("1");
        int j=0;
        while(j<p.size() && p[j]<=n && num[n]){
            while(n%p[j]==0){
                printf(" x %d",p[j]);
                n/=p[j];
            }
            ++j;
        }
        if(!num[n])
            printf(" x %d",n);
        puts("");
    }
    
    

#if !ONLINE_JUDGE
    printTime;
#endif
    return 0;
}
