/* PAT ID:1063  Set Similarity*/
/* 1. using STL AC it */
/* 2.try to build a tree youserlf.. */
/* method 1 Accepted! 25/25 */
#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef struct Node{
	set<int> Set;
}Node;
int main(){
	freopen("D:\\in.txt","r",stdin);
	vector<Node> vec;
	int n;
	scanf("%d",&n);
	vec.resize(n+1);
	int m;
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		int temp;
		for(int j=1;j<=m;j++){
			scanf("%d",&temp);
			vec[i].Set.insert(temp);
		}
	}
	int num_query,a,b;
	int little,other;
	scanf("%d",&num_query);
	while(num_query--){
		scanf("%d%d",&a,&b);
		int count=0;
		if(vec[a].Set.size()<vec[b].Set.size()){
			little=a;
			other=b;
		}
		else{
			 little=b;
			 other=a;
		}
		set<int>::iterator iter=vec[little].Set.begin();
		set<int>::iterator iter2;
		for(;iter!=vec[little].Set.end();iter++){
			iter2=vec[other].Set.find(*iter);
		//	cout<<*iter2<<endl;
			if(iter2!=vec[other].Set.end()) count++;
			//else count++;
			//cout<<"this is count "<<count<<endl;
		}
		float result=(float)count/(vec[a].Set.size()+vec[b].Set.size()-count);
		printf("%.1f%%\n",100*result);
	}
	return 0;
}