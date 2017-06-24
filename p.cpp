#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,p;
vector<int> res;
int max1=0;
long long int ipow(int base,int e)
{ 
  long long int res=1;
	for(int i=1;i<=e;i++)
		res*=base;
	return res;
}
int pathSum(vector<int> &path)
{
	int res=0;
	for(int i=0;i<path.size();i++)
		res+=path[i];
	return res;
}
bool dfs(int i,long long int sum,vector<int> &path)
{
	if(sum>n) return false;
	if(path.size()==k)
	{
		if(sum==n)
		{
		   int t=pathSum(path);
		   if(t>max1)
		   {
			max1=t;
			res=path;
		   }
		   return true;
	    }
		return false;
	}
    if(i==0) return path.size()==k&&sum==n;
	if(path.size()>k) return false;
		path.push_back(i);
		dfs(i,sum+ipow(i,p),path);		
		path.pop_back();
		path.push_back(i);
		dfs(i-1,sum+ipow(i,p),path);		
		path.pop_back();
	    dfs(i-1,sum,path);
	return false;
}
int main()
{
   scanf("%d%d%d",&n,&k,&p);
   vector<int> path;
   bool flag=dfs(n,0,path);
   //cout<<res.size()<<endl;
   if(flag) cout<<"Impossible"<<endl;
   else{
	   printf("%d = %d^%d",n,res[0],p);
	   for(int i=1;i<res.size();i++) printf(" + %d^%d",res[i],p);
	   printf("\n");
   }
   return 0;   
}
/* *********************************** */
/* Resarch about the return value.. */
/* 27/30 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,p;
vector<int> res;
int max1=0;
bool has=false;
long long int ipow(int base,int e)
{ 
  long long int res=1;
	for(int i=1;i<=e;i++)
		res*=base;
	return res;
}
int pathSum(vector<int> &path)
{
	int res=0;
	for(int i=0;i<path.size();i++)
		res+=path[i];
	return res;
}
bool dfs(int i,long long int sum,vector<int> &path)
{
	if(sum>n) return false;
	if(path.size()==k)
	{
		if(sum==n)
		{
		   int t=pathSum(path);
		   if(t>max1)
		   {
			max1=t;
			res=path;
		   }
		   has=true;
		   return true;
	    }
		return false;
	}
    if(i==0) return path.size()==k&&sum==n;
	if(path.size()>k) return false;
		path.push_back(i);
	    dfs(i,sum+ipow(i,p),path);		
		path.pop_back();
		path.push_back(i);
		dfs(i-1,sum+ipow(i,p),path);		
		path.pop_back();
	    dfs(i-1,sum,path);
        return false;
}
int main()
{
   scanf("%d%d%d",&n,&k,&p);
   vector<int> path;
   bool flag=dfs(n,0,path);
   //cout<<res.size()<<endl;
   if(!has) cout<<"Impossible"<<endl;
   else{
	   printf("%d = %d^%d",n,res[0],p);
	   for(int i=1;i<res.size();i++) printf(" + %d^%d",res[i],p);
	   printf("\n");
   }
   return 0;   
}