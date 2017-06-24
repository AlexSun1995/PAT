/* 1090. Highest Price in Supply Chain (25) */
/* starting at 2016-8-24 7:53 AM */
/* fa 8:25 22/25 1 case time out  */
/* running for PAT! */
/* in this case, it's clear that using BFS is definitely more efficient. */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

typedef struct Node{
	int parent;
}Node;
vector<Node> vec;
int dfs(int i,int root)
{
	int deepth=0;
	int cur=i;
	while(cur!=-1)
	{
		cur=vec[cur].parent;
		deepth++;
	}
	return deepth;
}
int main(){
	freopen("D:\\in.txt","r",stdin);
	int n;
	set<int> mySet; // suppliers set,which are not customers only
	double p,r;
	int root;
	scanf("%d%lf%lf",&n,&p,&r);
	vec.resize(n);
	vector<int> result;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&vec[i].parent);
		if(vec[i].parent!=-1) mySet.insert(vec[i].parent);
		else root=i;
	}
	set<int>::iterator iter;
	for(int i=0;i<n;i++)
	{
		iter=mySet.find(i);
		/* it's a consumer only */
		if(iter==mySet.end()) result.push_back(dfs(i,root)); 
	}
	/* find max in result */
    int cnt=0;
	int max=result[0];
	for(int i=0;i<result.size();i++)
	{
		if(result[i]>max){
			max=result[i];
			cnt=1;
		}
		else if(result[i]==max) cnt++;
	}
	/* count max number */
	printf("%.2lf %d\n",p*pow((1+r/100.0),(double)(max-1)),cnt);
	return 0;
}
/* zju rabbit CSDN 25/25 */
/*2015.7.30cyq*/  
#include <iostream>  
#include <queue>  
#include <vector>  
#include <fstream>  
using namespace std;  
  
//ifstream fin("case1.txt");  
//#define cin fin  
  
int main(){  
    int N;  
    double P,r;  
    cin>>N>>P>>r;  
  
    int root=0;  
    int x;  
    vector<vector<int> > tree(N);//tree[x]存储x的后继结点  
    for(int i=0;i<N;i++){  
        cin>>x;  
        if(x==-1)  
            root=i;  
        else{  
            tree[x].push_back(i);  
        }  
    }  
    //BFS  
    queue<int> cur,next;  
    cur.push(root);  
    int level=0;        //当前层  
    int levelCount=0;   //当前层的结点数  
    while(!cur.empty()){  
        level++;  
        levelCount=cur.size();  
        while(!cur.empty()){  
            int tmp=cur.front();  
            cur.pop();  
            for(auto it=tree[tmp].begin();it!=tree[tmp].end();++it){  
                next.push(*it);  
            }   
        }  
        swap(cur,next);  
    }  
    for(int i=1;i<level;i++)  
        P=P*(1+r/100);  
    printf("%.2f %d",P,levelCount);  
    return 0;  
}  