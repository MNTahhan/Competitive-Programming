/*
  any initial direction and position will work, just simulate the move
*/
#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
class RobotHerbDiv2{
public:
	int getdist(int T, vector <int> a){
		int d = 0, x = 0,y = 0;
		for(int i=0;i<T;++i){
			for(int j=0;j<a.size();++j){
				x += dx[d] * a[j];
				y += dy[d] * a[j];
				d = (d + a[j])%4;
			}
		}
		return abs(x)+abs(y);
	}
};
