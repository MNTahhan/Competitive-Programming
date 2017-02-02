
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
#if !ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

typedef complex<int> point;
#define EPS 1e-9
#define cp(a,b)  ( (conj(a)*(b)).imag() )
#define X real()
#define Y imag()

int ccw(point a, point b, point c) {
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);

  if (t > +EPS)
	return +1;
  if (t < -EPS)
	return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
	return -1;
  if (norm(v1) < norm(v2) - EPS)
	return +1;
  return 0;
}
bool intersect(point p1, point p2, point p3, point p4) {
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
        ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

int main() {
#if !ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
    //freopen("b.txt", "w", stdout);
    decTime;
#endif

    int n;
    while(scanf("%d",&n)>0 && n){
        vector<pair<point,point> >v;
        vector<int>flag(n,0);
        for(int i=0;i<n;++i){
            int x,y,a,b;
            scanf("%d%d%d%d",&a,&b,&x,&y);
            v.push_back(make_pair(point(a,b),point(x,y)));
        }
        int ans=0;
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                if(intersect(v[i].first,v[i].second,v[j].first,v[j].second)){
                    ++ans;
                    flag[i]=flag[j]=1;
                }
        for(int i=0;i<n;++i)
            ans+=2*!flag[i];
        printf("%d\n",ans);
    }
    
#if !ONLINE_JUDGE
    printTime;
#endif
    return 0;
}
