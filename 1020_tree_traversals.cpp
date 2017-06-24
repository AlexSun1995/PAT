/* patID:1020 Tree Traversals *//* Running for PAT! *//* 2016-7-13 18:40 *//* AC time 2016-7-14 23:33 *//* reference to a pointer that's crucial line: 32*//* recrusion can make your program pretty easy to write *//* as soon as you learned how to describe your solution to step in step*/#include<iostream>#include<vector>#include<stack>#include<queue>using namespace std; typedef struct Node{	int key;	Node *left;	Node *right; }Node; queue<Node *> que; /* if i want to use the recrusion method, what should I do?*/ void levelTraversal(Node * &head){		if(head!=NULL) que.push(head);		else cout<<"null pointer error"<<endl;		bool flag=true;		while(!que.empty()){			if(flag){				cout<<que.front()->key;				flag=false;			}			else cout<<" "<<que.front()->key;			if(que.front()->left) que.push(que.front()->left);			if(que.front()->right) que.push(que.front()->right);			que.pop();		} } /* if I do not use the reference to a pointer, I ONLY want  */ /* to use the pointer,what should I do with that? */ void buildTree(Node * &head,const vector<int> &postorder,const vector<int> &inorder,int s1,int e1,int s2,int e2) {	 //cout<<s1<<" "<<e1<<" "<<s2<<" "<<e2<<endl;	 if(s1>e1||s2>e2||s1<0||s2<0){		//cout<<"fuck dog"<<endl;        return;			 }	 if(head==NULL){		head = new Node;        head->left=NULL;		        head->right=NULL;        head->key=postorder[e1];			 }	 int pos=-1;	 /* find the index which represent to the item should be the root */	 for(int i=s2;i<=e2;i++){		if(inorder[i]==postorder[e1]){			pos=i;			break;		} 	 }	 if(pos==s2){		 buildTree(head->right,postorder,inorder,s1,e1-1,s2+1,e2);	 }	 else if(pos==e2){		 buildTree(head->left,postorder,inorder,s1,e1-1,s2,e2-1);	 }	 else{		buildTree(head->left,postorder,inorder,s1,pos-s2+s1-1,s2,pos-1);        buildTree(head->right,postorder,inorder,pos-s2+s1,e1-1,pos+1,e2);			 } }int main(){	int len;	vector<int> postorder,inorder;	//freopen("D:\\in.txt","r",stdin);	cin>>len;	postorder.resize(len);	inorder.resize(len);	Node *head=NULL; 	for(int i=0;i<len;i++) scanf("%d",&postorder[i]);	for(int i=0;i<len;i++) scanf("%d",&inorder[i]);    buildTree(head,postorder,inorder,0,len-1,0,len-1);	levelTraversal(head);	return 0;}