//23/25 I've got no idea what's the matter..
//this version in not accepted, it's not perfect,
//if the sequece is like #####*********** which '#' is
//the result element,then the code will not get the 
//correct answer,the correct way to do this problem is 
//search every maxinum value of each element,ans print
//the maxinum answer,use b-search is a good solution.
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include<queue>
#include<vector>
using namespace std;
int main()
{
 freopen("/home/alexsun/in.txt","r",stdin);
 vector<long long> vec;
 long long  n,p;
 long long  ans;
 scanf("%lld %lld",&n,&p);
 vec.resize(n);
 for(int i=0;i<n;i++){
	 scanf("%lld",&vec[i]);
 }
 sort(vec.begin(),vec.end());
 ans = n;
 int m,M;
 m = 0;
 M = n-1;
 while(m<=M){
   if(vec[m]*p>=vec[M]){
	   break;
   }
   else{
	   if(m+1<=M){
          if(vec[M]<=vec[m+1]*p)
		  {
			  ans--;
			  break;
		  }
	   }
	   if(M-1>=m){
           if(vec[M-1]<=vec[m]*p){
			   ans--;
			   break;
		   }
	   }
      if(m==M){
        ans--;
        break;
      }
      ans-=2;
      m++;
      M--;
   }
 }
  cout<<ans<<endl;
  return 0;
}

