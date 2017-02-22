// got accepted,this version use totally a different 
// way than what you first try,when use b-search faces
//none distincted sequence, it's necessary 
// to change the function of what you thinked before.
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include<vector>
#define MAX 100005
using namespace std;
int sum[MAX];
vector<int> vec;
//return the first position that meet 
//sum[index] >=x  
int upper_bound(int start,int end,int x){
  int left = start;
  int right = end;
  int mid;
  while(left<right){
	  mid = (left + right)/2;
      if(sum[mid]>=x){
		  right = mid;
	  }
	  else if(sum[mid]<x){
		  left = mid + 1;
	  }
  }
  return left;
}
int main()
{
  freopen("/home/alexsun/in.txt","r",stdin);
  int n,k;
  int nearest = MAX;
  sum[0] = 0;
  scanf("%d%d",&n,&k);
  vec.resize(n+5);
  for(int i=1;i<=n;i++){
	  scanf("%d",&vec[i]);
      sum[i] = sum[i-1] + vec[i];
  }
  for(int i=1;i<=n;i++){
	  int j = upper_bound(i,n,k+sum[i-1]);
	  if(sum[j] - sum[i-1]==k){
		  nearest = k;
		  break;
	  }
	  else if(sum[j] - sum[i-1]>=k&&sum[j] - sum[i-1]<nearest){
		nearest = sum[j] - sum[i-1];
	  }
  }
  for(int i=1;i<=n;i++){
	  int j = upper_bound(i,n,nearest+sum[i-1]);
      if(sum[j] - sum[i-1]==nearest){
          printf("%d-%d\n",i,j);
	  }
  }
  return 0;
}

