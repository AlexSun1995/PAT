/* PAT 1110 Compete Binary Tree */
/* Starting at 2016 8-08 2:34 Pm */
/* 3:20 Pm 16/25 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
typedef struct Node{
	int id;
	int left;
	int right;
	int pos;   // position in a CBT
}Node;
vector<int> vec_tag;
/* give every child a new mark which is their position in the tree */
void childMark(vector<Node> &vec,int root,int tag){
	vec[root].pos=tag;
	vec_tag.push_back(tag);
	if(vec[root].left!=-1){
		childMark(vec,vec[root].left,2*tag);
	}
	if(vec[root].right!=-1){
		childMark(vec,vec[root].right,2*tag+1);
	}
	return;
}
int main(){
	int n;
	freopen("D:\\in.txt","r",stdin);
	vector<Node> vec;
	scanf("%d\n",&n);
	vec.resize(n);
	/* A set which stores the exits children,which one not in,which is the root */
	set<int> childSet;
	string l,r;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		//cout<<l<<"/"<<r<<endl;
		if(l!="-"){
			int num;
			const char *temp=l.c_str();
			if(l.size()>1){
				num=10*(temp[0]-'0')+(temp[1]-'0');
			}else num=temp[0]-'0';
			vec[i].left=num;
			childSet.insert(num);
		}else vec[i].left=-1;
		if(r!="-"){
			int num;
			const char *temp=r.c_str();
			if(r.size()>1){
				num=10*(temp[0]-'0')+(temp[1]-'0');
			}else num=temp[0]-'0';
			vec[i].right=num;
			childSet.insert(num);
		}else vec[i].right=-1;
	}
	int root;
	set<int>::iterator iter;
	/* find root */
	for(int i=0;i<n;i++){
		iter=childSet.find(i);
		if(iter==childSet.end()){
			root=i;
			break;
		}
	}
	childMark(vec,root,1);
	/* find The Max Element in vec_tag */
	int max=vec_tag[0];
	for(int i=0;i<vec_tag.size();i++) if(vec_tag[i]>max) max=vec_tag[i];
	if(max==n){
		cout<<"YES ";
		for(int i=0;i<n;i++){
			if(vec[i].pos==n){
				cout<<i<<endl;
				break;
			}
		}
	}
	else{
		cout<<"NO "<<root<<endl;
	}
	return 0;	
}