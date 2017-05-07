#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0 && (n || m)) {
		if (n > m)
			puts("0.000000");
		else
			printf("%.6lf\n", (m - n + 1.) / (m + 1.));
	}
	return 0;
} 
