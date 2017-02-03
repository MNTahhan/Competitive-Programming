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

int n,m,q,c[220],cyc[220],vis[220],vs,reach[220];
vector<int>adj[220];
ll cost[220];

int main() {
#if !ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
    //freopen("b.txt", "w", stdout);
    decTime;
#endif
    
    int h=1;
    while(scanf("%d",&n)>0){
        ++vs;
        for(int i=1;i<=n;++i){
            cost[i]=100000;
            cyc[i]=0;
            reach[i]=0;
            adj[i].clear();
            scanf("%d",&c[i]);
        }
        scanf("%d",&m);
        vector<pair<int,int> >e;
        while(m--){
            int u,v;
            scanf("%d%d",&u,&v);
            e.push_back(make_pair(u,v));
            adj[u].push_back(v);
        }
        queue<int>qu;
        qu.push(1);
        vis[1]=vs;
        reach[1]=1;
        while(qu.size()){
            int fr=qu.front(); qu.pop();
            for(int i=0;i<adj[fr].size();++i)
                if(vis[adj[fr][i]]!=vs){
                    qu.push(adj[fr][i]);
                    vis[adj[fr][i]]=vs;
                    reach[adj[fr][i]]=1;
                }
        }
        cost[1]=0;
        for(int i=1;i<n;++i)
            for(int j=0;j<e.size();++j){
                ll tmp=c[e[j].second]-c[e[j].first];
                tmp=tmp*tmp*tmp;
                tmp+=cost[e[j].first];
                if(tmp<cost[e[j].second])
                    cost[e[j].second]=tmp;
            }
        ++vs;
        for(int j=0;j<e.size();++j){
            ll tmp=c[e[j].second]-c[e[j].first];
            tmp=tmp*tmp*tmp;
            tmp+=cost[e[j].first];
            if(tmp<cost[e[j].second]){
                cyc[e[j].second]=1;
                qu.push(e[j].second);
                vis[e[j].second]=vs;
            }
        }
        while(qu.size()){
            int u=qu.front(); qu.pop();
            for(int i=0;i<adj[u].size();++i)
                if(vis[adj[u][i]]!=vs){
                    vis[adj[u][i]]=vs;
                    qu.push(adj[u][i]);
                    cyc[adj[u][i]]=1;
                }
        }
        scanf("%d",&q);
        printf("Set #%d\n",h++);
        while(q--){
            int u;
            scanf("%d",&u);
            if(cost[u]<3 || cyc[u] || !reach[u])
                puts("?");
            else
                printf("%lld\n",cost[u]);
        }
    }
    

#if !ONLINE_JUDGE
    printTime;
#endif
    return 0;
}
