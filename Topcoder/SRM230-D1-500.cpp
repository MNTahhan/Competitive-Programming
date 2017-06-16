/*
	The idea: a/b is divisible by x if the number of x's in a is larger than b, and as we can loop on all the numbers in a raw, we 
		  can test this property for all the 6 numbers.
		  how to count number of d's in n! : http://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
*/
#include<bits/stdc++.h>
using namespace std;
int calc(int n,int d){
	// count the number d's in n!
	int cnt=0;
	for(int i=d;n/i>=1;i*=d)
		cnt+=n/i;
	return cnt;
}
class PascalCount{
public:
	int howMany(int n, int d){
		int ans=0;
		int flag=0;
		if(d==4)
			d=2,flag=1;
		if(d==2 || d==3 || d==5){
			int num = calc(n,d);
			for(int k=1;k<n;++k){
				int den = calc(k,d) + calc(n-k,d);
				if(num && num-flag>den) // in the case of d=4, there must be two 2's in the numerator
					++ans;
			}
		}
		if(d==6){
			int num1 = calc(n,2);
			int num2 = calc(n,3);
			for(int k=1;k<n;++k){
				int den1 = calc(k,2) + calc(n-k,2);
				int den2 = calc(k,3) + calc(n-k,3);
				if(num1>den1 && num2>den2)
					++ans;
			}
		}
		return ans;
	}
};
