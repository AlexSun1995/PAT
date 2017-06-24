/* PATID:1052 Linked List Sort */
/* Running for PAT! */
/* starting time:2016-07-18 10:34 AM */
/* First Submit Time :2016-07-18 12:15 PM 21/25 */
/* 2016-07-18 12:35 PM 24/25  segment error */
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef struct Node{
	int address;
	int key;
	int next;
}Node;
bool comp(const Node &a,const Node &b){
	return a.key<b.key;
}
int main(){
    //freopen("D:\\in.txt","r",stdin);
	int N,start;
	vector<Node> vec;
	map<int,int> add2Index;
	scanf("%d%d",&N,&start);
	vec.resize(N);
	for(int i=0;i<N;i++){
		int add,key,next;
		scanf("%d%d%d",&add,&key,&next);
		add2Index.insert(make_pair(add,i));
		vec[i].address=add;
		vec[i].key=key;
		vec[i].next=next;
	}
	vector<Node> list;
	//Node temp;
	//vector<Node>::iterator iter=vec.begin();
	int pointer=start;
	while(pointer!=-1){
		list.push_back(vec[add2Index[pointer]]);
		pointer=vec[add2Index[pointer]].next;
	}
	sort(list.begin(),list.end(),comp);
	vector<Node>::iterator iter=list.begin();
	printf("%d %05d\n",list.size(),iter->address);
	for(;iter!=list.end();){
		printf("%05d ",iter->address);
		printf("%d ",iter->key);
		iter++;
		if(iter==list.end()) printf("%d\n",-1);
		else printf("%05d\n",iter->address);
	}
	return 0;
}	
/* ********************************* */
/* Accepted! */
//1052. Linked List Sorting (25)
//2016-9-9 16:27
//16:46 18/25
//19:00 25/25
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef struct Node{
	int key;
	int add;
	int next;
}Node;
bool cmp(const Node &a,const Node &b)
{
	return a.key < b.key;
}
int main()
{
	int n,s;
	freopen("D:\\in.txt","r",stdin);
	scanf("%d%d",&n,&s);
	vector<Node> vec1(n);
	vector<Node> vec;
	map<int,int> map1;
	int realen,next;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&vec1[i].add,&vec1[i].key,&vec1[i].next);
		map1[vec1[i].add]=i;  
	}
	map1[-1]=-1;
	int cur=map1[s];
	while(cur!=-1)
	{
		vec.push_back(vec1[cur]);
		cur=map1[vec1[cur].next];
	}
	sort(vec.begin(),vec.end(),cmp);
	if(vec.size()==0)
	{
		printf("%d %d\n",0,-1);
		return 0;
	} 
	printf("%d %05d\n",vec.size(),vec[0].add);
	int len=vec.size();
	for(int i=0;i<len-1;i++)
	{
		printf("%05d %d %05d\n",vec[i].add,vec[i].key,vec[i+1].add);
	}
    printf("%05d %d %d\n",vec[len-1].add,vec[len-1].key,-1);
	return 0;
}