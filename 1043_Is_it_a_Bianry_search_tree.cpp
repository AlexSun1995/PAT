/* patId 1043 is it a Bianry search tree */
// Running for PAT! 2016-7-8 22:09
/* AC TIME:2016-7-12 10:48 */
/* you must know your shortage, the pointer and the recursion */
#include<iostream>
#include<queue>
#define ElemType int
#define BinarySearchTree Node*
#define nullptr NULL
using namespace std;
typedef struct Node{
  ElemType data;
  Node* left;
  Node* right;   
}Node;
queue<ElemType> que;
queue<ElemType> que1;
/* this step is keen but you really need to understand */
BinarySearchTree insert(BinarySearchTree head,ElemType data){
   if(head==NULL){
     head=(BinarySearchTree)malloc(sizeof(Node));
     head->left=NULL;
     head->right=NULL;
     head->data=data;
   }
   else if(data<head->data){
        head->left=insert(head->left,data);
   }
   else if(data>=head->data){
        head->right=insert(head->right,data);
   } 
   return head;
}
BinarySearchTree buildBSTree(BinarySearchTree tree,ElemType array[],int size){
      tree->data=array[0];
	  tree->left=NULL;
	  tree->right=NULL;
      for(int i=1;i<size;i++)
      {
        BinarySearchTree head=tree;
        insert(head,array[i]);   
      }
      return tree;
} 
void pre_order(BinarySearchTree tree){
    que.push(tree->data);
    if(tree->left!=nullptr){
      pre_order(tree->left);
    }
    if(tree->right!=nullptr){
      pre_order(tree->right);                     
    }
}
void r_preorder(BinarySearchTree tree){
	que1.push(tree->data);
    if(tree->right!=nullptr){
		r_preorder(tree->right);
	}
    if(tree->left!=nullptr){
	    r_preorder(tree->left);
	}	
}
void print_postorder(BinarySearchTree tree){
	static bool firstTime=true;
	if(tree->left!=nullptr){
		print_postorder(tree->left);
	}
    if(tree->right!=nullptr){
	   print_postorder(tree->right);
	}
	if(firstTime){
		printf("%d",tree->data);
		firstTime=false;
	}
	else printf(" %d",tree->data);
}
void print_postorder2(BinarySearchTree tree){
	static bool firstT=true;
	if(tree->right!=nullptr){
		print_postorder2(tree->right);
	}
    if(tree->left!=nullptr){
	   print_postorder2(tree->left);
	}
	if(firstT){
		printf("%d",tree->data);
		firstT=false;
	}
	else printf(" %d",tree->data);
}
int main(){
   //freopen("D:\\in.txt","r",stdin);
   int len;
   scanf("%d",&len);
   int *array=(int *)malloc((len+1)*sizeof(int));
   bool flag=true;
   bool flag1=true;
   BinarySearchTree tree = (BinarySearchTree)malloc(sizeof(Node));
   for(int i=0;i<len;i++){
      scanf("%d",&array[i]);
   } 
   tree = buildBSTree(tree,array,len);
	   pre_order(tree);
	   r_preorder(tree); 
   for(int i=0;i<len;i++)
   {
	    if(array[i]==que.front()){
			que.pop();
			continue;
		} 
	    else{
		    flag=false;
		    break;
	    }
   }
    for(int i=0;i<len;i++)
   {
	    if(array[i]==que1.front()){
			que1.pop();
			continue;
		} 
	    else{
		    flag1=false;
		    break;
	    } 
   }
   if(!flag&&!flag1){
	   printf("NO\n"); 
   }
   else{
	   printf("YES\n");
	   if(flag)print_postorder(tree);
	   else print_postorder2(tree);	   
   }
   
   return 0;
}
