/* using a queue at the first level, when the root has no child
   push 1 and return, else push all the children of root into 
   queue.
   decide all the elements in the queue, if the element has child
   or children,push them in the queue,else  we consider it as 
   a leave and 1 will be plused on the counter.
   ************************************************
   partly correct.6/30 2016/5/15
   ************************************************
 */
#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;
class myList{
  public :
  list<int> parent_child;
  bool isParent;
  list<int>::iterator begin(){
	  return parent_child.begin();
  }
  list<int>::iterator end(){
	  return parent_child.end();
  }
  void push_back(int temp){
	  parent_child.push_back(temp);
  }
  int size(){
	  return parent_child.size();
  }
};
typedef struct{
	int level;
	int count;
}LevelCount;
int main(){
	myList parent_child[100];
	LevelCount levelCount;
	levelCount.level=1;
	levelCount.count=0;
	vector<int> levelList;
	queue<int> levelQuene;
	int level_pointer=1;
	int total_nodes;
	int non_leaf_nodes;
	int nodeId;
	int child_num;
	int tempNode;
	scanf("%d",&total_nodes);
	scanf("%d",&non_leaf_nodes);
	for(int i=0;i<non_leaf_nodes;i++){
		scanf("%d", &nodeId);
		scanf("%d", &child_num);
		parent_child[nodeId].isParent=true;
		while(child_num--){
			scanf("%d",&tempNode);
			parent_child[nodeId].push_back(tempNode);
		}
	}
	list<int>::iterator iter=parent_child[1].begin();
	if(parent_child[1].size()!=0){
		levelList.push_back(0);
	}else if(total_nodes==0){
		cout<<0;
		return 0;
	}else if(non_leaf_nodes==0){
		cout<<1;
		return 0;
	}
	for(;iter!=parent_child[1].end();iter++){
	   levelQuene.push(*iter);  
		 //mark;
	}
	levelCount.count=0;
	int size;
	//cout<<"qsize1: "<<levelQuene.size()<<endl;    //1
	while(!levelQuene.empty()){
		size=levelQuene.size();
		//cout<<"qsize2: "<<levelQuene.size()<<endl;    //1
		// for(int i=0;i<size;i++){
			// if(parent_child[levelQuene.front()].isParent==true){
				   // iter=parent_child[levelQuene.front()].begin();
			  // for(;iter!=parent_child[levelQuene.front()].end();iter++){
				  // levelQuene.push(*iter);
				  // levelCount.count++;
			    // }
			// }else{
				// //
			// }
			// levelQuene.pop();
		// }
		// levelCount.level++;
		// levelList.push_back(levelCount.count);
		// levelCount.count=0;
		for(int i=0;i<size;i++){
			if(parent_child[levelQuene.front()].isParent==true){
				iter=parent_child[levelQuene.front()].begin();
			    for(;iter!=parent_child[levelQuene.front()].end();iter++)
				    levelQuene.push(*iter);
			}else{
				levelCount.count++;
			}
			levelQuene.pop();
		}
		levelList.push_back(levelCount.count);
		levelCount.count=0;
	}
	vector<int>::size_type ix=0;
	for(;ix!=levelList.size()-1;ix++)
		  cout<<levelList[ix]<<' ';
	  cout<<levelList[ix];
	  printf("\n");
	return 0;
}
/*
one correct version. 
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int MAX_SIZE=100;
typedef struct node
{
	int id;
	int childs_num;
	vector<int> childs;
}Node;


void count_leafs(const Node *tree,Node node,map<int,int>& m,int depth)
{
	if(m[depth]==0) m[depth]=0;
	if(node.childs_num==0){
		++m[depth];
		return;
	}
	vector<int> childs=node.childs;
	for(size_t i=0;i<childs.size();++i){
		count_leafs(tree,tree[childs[i]],m,depth+1);
	}
}

int main()
{
	int n, m;
	cin>>n>>m;
	Node tree[MAX_SIZE];
	for(int i=0;i<MAX_SIZE;++i){
	    tree[i].id=0;
		tree[i].childs_num=0;
	}
	int id,k;
	while(m--){
		cin>>id>>k;
		tree[id].id=id;
		tree[id].childs_num=k;
		int child;
		while(k--){
			cin>>child;
			tree[id].childs.push_back(child);
		}
	}
	map<int,int> result;
	count_leafs(tree,tree[1],result,1);
	bool first=true;
	for(map<int,int>::iterator iter=result.begin();iter!=result.end();++iter){
		if(first){
			cout<<iter->second;
			first=false;
		}else{
			cout<<" "<<iter->second;
		}
	}
	return 0;
}
/*
9 5
01 2 02 03
02 1 04
03 2 05 06
05 2 07 08
08 1 09
*/
