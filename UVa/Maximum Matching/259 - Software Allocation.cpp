/*
  The idea: consider every copy of the characters as separate node, number them starting from 10, and computers from [0-9] then do
            a maximum matching to find the best answer
*/
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "inc.h"
#endif
using namespace std;
typedef long long ll;

const int N = 550;
int vis[N], vs, match[N];
char mp[N];
vector<int> adj[N];
int DFS(int u) {
	vis[u] = vs;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (match[v] == -1 || vis[match[v]] != vs && DFS(match[v])) {
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.txt", "r", stdin);
//	freopen("a.txt", "w", stdout);
	decTime;
#endif

	while (cin.peek() != -1) {
		for (int i = 0; i < N; ++i) {
			adj[i].clear();
			match[i] = -1;
		}
		string s;
		vector<int> v;
		int idx = 10;
		while (getline(cin, s) && s != "") {
			v.push_back(s[0] - 'A');
			for (int k = 0; k < s[1] - '0'; ++k) {
				mp[idx] = s[0];
				for (int j = 3; j + 1 < s.size(); ++j) {
					adj[idx].push_back(s[j] - '0');
				}
				++idx;
			}
		}
		int ans = 0;
		for (int i = 10; i < idx; ++i) {
			++vs;
			ans += DFS(i);
		}
		if (ans < idx - 10) {
			puts("!");
			continue;
		}
		for (int i = 0; i < 10; ++i)
			printf("%c", match[i] == -1 ? '_' : mp[match[i]]);
		puts("");
	}

#ifndef ONLINE_JUDGE
	printTime;
#endif
	return 0;
}
