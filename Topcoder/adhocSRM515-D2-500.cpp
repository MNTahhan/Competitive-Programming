/*
  The same idea in the editorial: https://apps.topcoder.com/wiki/display/tc/SRM+515
*/
#include<bits/stdc++.h>
using namespace std;

class RotatedClock{
public:
	string getEarliest(int h, int m){
		for(int i=0;i<360;i+=30){
        int H = (h+i)%360;
        int M = (H*12)%360;
        if( M==(m+i)%360){
            	    H/=30;
            	    M/=6;
            	    string s = "";
            	    if(H<10)s="0", s+=H%10+'0';
            	    else s+=H%10+'0',H/=10,s+=H%10+'0',reverse(s.begin(),s.end());
            	    s+=":";
            	    string m="";
            	    if(M<10)m="0",m+=M%10+'0';
            	    else m+=M%10+'0',M/=10,m+=M%10+'0',reverse(m.begin(),m.end());
            	    s+=m;
            	    return s;
        	}
    	}   
    	return "";
	}
};		 
