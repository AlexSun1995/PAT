// this version get timeout.21/25
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include<vector>
//only in test of git....
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//>>>>>>>>>come on>>>>>>>>>>>>>>>>>>>>>>>
//>>>>>>>>>>>>>
//>>>>>>>>>>>>>>>>>>>>>>>>>>>
using namespace std;
#define MAX 666666
vector<int> vec;
int n;
int target;
int main()
{
  freopen("/home/alexsun/in.txt","r",stdin);
  scanf("%d%d",&n,&target);
  vec.resize(n);
  vector<pair<int,int> > ans;
  int tmp;
  int meet = MAX;
  for(int i=0;i<n;i++){
     scanf("%d",&vec[i]);
  }
  for(int i=0;i<n;i++){
	  pair<int,int> tp;
	  tmp = 0;
	  tp.first = i+1;
	  for(int j=i;j<n;j++){
		  tmp+=vec[j];
		  if(tmp>=target&&tmp<meet){
			  ans.clear();
			  meet = tmp;
              tp.second = j+1;
			  ans.push_back(tp);
			  break;
		  }
		  else if(tmp>=target&&tmp==meet){
			  tp.second = j+1;
              ans.push_back(tp);
              break;
		  }
	  } 
  }
  for(int i=0;i<ans.size();i++){
	  printf("%d-%d\n",ans[i].first,ans[i].second);
  }
  return 0;
}

