/* PAT 1101 quick sort */
/* find the candinate pivot for each a[i] in the integer sequence a  */
/*  */
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	vector<int> vec;
	vector<int> vec2;
	vector<int> res;
	scanf("%d",&n);
	vec.resize(n);
	for(int i=0;i<n;i++) scanf("%d",&vec[i]);
	vec2=vec;
	sort(vec2.begin(),vec2.end());
	map<int,int> map1;
	for(int i=0;i<n;i++) map1[vec2[i]]=i; 
	int cur_max=vec[0];
	for(int i=0;i<n;i++)
	{
		if(vec[i]>cur_max) cur_max=vec[i];
		if(vec[i]==cur_max&&map1[vec[i]]==i) res.push_back(vec[i]);
	}
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	if(res.size()>0)
	{
		printf("%d",res[0]);
	    for(int i=1;i<res.size();i++) printf(" %d",res[i]);
	}
	printf("\n");
	return 0;
}