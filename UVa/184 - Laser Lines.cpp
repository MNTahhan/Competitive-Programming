#include <bits/stdc++.h>
using namespace std;

const double EPS = (1e-8);
int dcmp(double a, double b) {	return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1;	}
typedef complex<int> point;
#define X real()
#define Y imag()
#define length(a)               (hypot((a).imag(), (a).real()))
bool isPointOnSegment(point a, point b, point c) {
	int pos=a.X*b.Y + b.X*c.Y + c.X*a.Y; 
	int neg=a.X*c.Y + b.X*a.Y + c.X*b.Y; 
	return pos==neg;
}
vector<pair<int,int> >v;

int main() {
	// your code goes here
	int r=0;
	int x,y;
	while(scanf("%d%d",&x,&y)>0 && (x||y)){
		++r;
		v.clear();
		v.push_back(make_pair(x,y));
		while(scanf("%d%d",&x,&y)>0 && (x||y))
			v.push_back(make_pair(x,y));
		vector<vector<pair<int,int> > >res;
		for(int i=0;i<v.size();++i)
		for(int j=i+1;j<v.size();++j)
		if(i!=j){
			vector<pair<int,int> >ans;
			ans.push_back(v[i]);
			ans.push_back(v[j]);
			for(int k=0;k<v.size();++k)
				if(k!=i && k!=j){
					point a(v[i].first,v[i].second);
					point b(v[j].first,v[j].second);
					point c(v[k].first,v[k].second);
					if(isPointOnSegment(a,b,c))
						ans.push_back(v[k]);
				}
			sort(ans.begin(),ans.end());
			if(ans.size()>2)
				res.push_back(ans);
		}
		if(!res.size())
			puts("No lines were found");
		else{
			sort(res.begin(),res.end());
			for(int i=0;i<res.size();++i)
			for(int j=0;j<res.size();++j)
			if(i!=j && res[i].size() && res[j].size()){
				int cnt=0,flag[2][11]={0},mark=0;
				for(int k=0;k<res[i].size() && !mark;++k){
					for(int e=0;e<res[j].size();++e)
						if(res[i][k]==res[j][e] && !flag[0][k] && !flag[1][e]){
							flag[0][k]=1;
							flag[1][e]=1;
							++cnt;
							break;
						}
					if(cnt==res[j].size())
						mark=1;
				}
				if(mark)
					res[j].clear();
			}
			puts("The following lines were found:");
			for(int i=0;i<res.size();++i){
				if(res[i].size()){
					for(int j=0;j<res[i].size();++j)
						printf("(%4d,%4d)",res[i][j].first,res[i][j].second);
					puts("");
				}
			}
		}
	}
	return 0;
}
