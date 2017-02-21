//pat 1065 prime facots,using dfs.
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include<vector>
#include<cmath>
using namespace std;
vector<long int> vec;
long int n;
bool isPrime(long int n){
   if(n==1) return false;
   long int sq = (long int)sqrt((double)n);
   long int i  = 2;
   bool flag =  true;
   for(;i<=sq;i++){  
      if(n%i==0){
		  flag = false;
		  break;
	  }
   }
   return flag;
}
void dfs(long int n){
   long int i = 2;
   for(;i<=n;i++){
      if(isPrime(i)&&n%i==0){
		  vec.push_back(i);
          dfs(n/i);
		  break;
	  }
   }
}
int main()
{
  cin>>n;
  if(n==1){
   cout<<1<<"="<<1<<endl;
   return 0;
  }
  dfs(n);
  sort(vec.begin(),vec.end());
  int k,p;
  long int cur;
  bool first = true;
  for(int i=0;i<vec.size();){
     cur =  vec[i];
     k = 1;
     p = i + 1;
	 while(p<vec.size()&&vec[p]==cur) {
         k++;
		 p++;
	 }
     if(first){
		 first = false;
         printf("%ld=%ld",n,cur);
		 if(k>1){
			 printf("^%d",k);
		 }
		 i+=k;
		 continue;
	 }
     if(k>1){
		 printf("*%ld^%d",cur,k);
	 }
	 else if(k==1) printf("*%ld",cur);
	 i+=k;
  }
  cout<<endl;
  return 0;
}

