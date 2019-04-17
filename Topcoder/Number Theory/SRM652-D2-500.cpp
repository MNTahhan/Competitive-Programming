/*
  The idea: in every permuation, result of f(position of '1')=1, and all multiples of this position also
            so the answer is the LCM for all positions in permuation
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	while(a && b)
		if(a>=b) a%=b;
		else b%=a;
	return a+b;
}
ll lcm(ll a, ll b){
	return a/gcd(a,b)*b;
}
class ThePermutationGameDiv2{
public:
	long long findMin(int N){
		ll ans=1;
		for(int i=1;i<=N;++i)
			ans=lcm(ans,i);
		return ans;
	}
};
