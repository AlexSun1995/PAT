#include<iostream>
#include<list>
#include<queue>
#define MAX_SIZE 100
using namespace std;
int main(){
	int total_nodes;
	int id[MAX_SIZE];
	list<int> parent_child[MAX_SIZE];
	queue<int> levelQueue;
	int level=0;
	int level_leaves=0;
	int flagElement=1;
	bool firstTimeLoop=true;
	int parent; 
	int numOfChild;
	int child;
	int total_nonel_nodes;
	cin>>total_nodes>>total_nonel_nodes;
	for(int i=0;i<total_nonel_nodes;i++)
	{
       cin>>parent;
	   cin>>numOfChild;
	   while(numOfChild--){
		   cin>>child;
		   parent_child[parent].push_back(child);
	   }
	}
   while(flagElement!=total_nonel_nodes){
	  while(firstTimeLoop==true||!levelQueue.empty()){
		if(firstTimeLoop) flagElement=1;
		else flagElement=levelQueue.top();
		levelQueue.pop();
		firstTimeLoop=false;
		if(parent_child[flagElement].size()>0){
			list<int>::iterator iter=parent_child[flagElement].begin();
			 while(iter!=parent_child[flagElement].end()){
				 iter++;
				 levelQueue.push(*iter);
			 }
		}else{
			level_leaves++;
		}
	  }
	  cout<<level<<" "<<level_leaves;
	  level++;
   }
    return 0;
}