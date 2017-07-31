/*
  The idea: we can compute the different values of x from the inequality a+b*c<=upperBound, and iterate through all the values in geometric
  progression (they are log2(1e12) in worst case), increase the counter for every one that does not accure in the arithmatic progression.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class CountingSeries{
public:
	long long countThem(long long a, long long b, long long c, long long d, long long u){
		ll x = a <= u ? (u - a) / b + 1 : 0;
		while(c<=u){
			if(c<a || (c-a)%b)
				++x;
			c*=d;
			if(d==1) 
				break;
		}
		return x;
	}
};
