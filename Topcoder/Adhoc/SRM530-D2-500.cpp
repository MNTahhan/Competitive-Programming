/*
  The idea: visit all '.' in the cake, when you reach one, try to put it on the first '.' on the cutter, check that this set is valid
*/
#include<bits/stdc++.h>
using namespace std;
vector<string>ocake, cutter, cake;
int n, m;
void calc(int x, int y) {
	int b = 0;
	for(int j = 0; j<cutter[0].size(); ++j)
		if(cutter[0][j] == '.') {
			b = j;
			break;
		}
	if(x + cutter.size() > n)
		return;
	if(y - b + cutter[0].size() > m)
		return;
	bool flag = true;
	for(int i = x; i<x + cutter.size(); ++i)
		for(int j = y - b; j<y - b + cutter[0].size(); ++j) {
			int c1 = i - x;
			int c2 = j - y + b;
			if(cutter[c1][c2] == '.' && cake[i][j] == 'X')
				flag = false;
			if(cutter[c1][c2] == '.' && ocake[i][j] == '.')
				flag = false;
		}
	if(!flag)
		return;
	for(int i = x; i<x + cutter.size(); ++i)
		for(int j = y - b; j<y - b + cutter[0].size(); ++j) {
			int c1 = i - x;
			int c2 = j - y + b;
			if(ocake[i][j] == 'X')
				ocake[i][j] = cutter[c1][c2];
		}
}
class GogoXCake {
public:
	string solve(vector <string> cake, vector <string> cutter) {
		::cutter = cutter;
		::cake = cake;
		n = cake.size();
		m = cake[0].size();
		ocake = cake;
		for(int i = 0; i<n; ++i)
			for(int j = 0; j<m; ++j)
				ocake[i][j] = 'X';
		for(int i = 0; i<n; ++i)
			for(int j = 0; j<m; ++j) {
				if(cake[i][j] == '.' && ocake[i][j]=='X') {
					calc(i, j);
				}
			}
		return ocake == cake ? "YES" : "NO";
	}
};
