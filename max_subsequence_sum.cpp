/* Max Subsequence Sum */
/* almost correct. 22/25 2016-5-19  */
/* this algorithm thinking is not by your own */
/* just try to understand its core algorithm */
/* by Alex Sun */
#include<iostream>
#include<vector>
#define MAX_SIZE 10000
using namespace std;
int startPos,endPos;
int MaxSubsequenceSum(const int A[],int N){
	int thisSum,maxSum;
	startPos=0;
	int tempStart=0;
	endPos=0;
	thisSum=0;
	maxSum=0;
	for(int i=0;i<N;i++){
		thisSum+=A[i];
		//cout<<"thisSum "<<thisSum<<endl;
		if(thisSum>maxSum){
			 endPos=i;
			 startPos=tempStart;
			 maxSum=thisSum;
		}
		else if(thisSum<=0){
			tempStart=i+1;
			thisSum=0;
		}
	}
	return maxSum;
}
int main(){
	//freopen("D:\\in.txt","r",stdin);
	int n,size;
	scanf("%d",&n);
    size=n;	
	int list[MAX_SIZE];
	int temp,i;
	i=0;
	while(n--){
		scanf("%d",&temp);
		list[i]=temp;
		i++;
	}
	int result=MaxSubsequenceSum(list,size);
	if(result>0){
		cout<<result;
	    cout<<" "<<list[startPos]<<" "<<list[endPos];
	}
	else {
        cout<<0;
        cout<<" "<<list[0]<<" "<<list[size-1];		
	}
	return 0;
}
/*******************************************************/
  /* Max Subsequence Sum */
/* absolutely correct. 25/25 2016-5-19 14:26 */
/* this algorithm thinking is not by your own */
/* just try to understand its core algorithm */
/* by Alex Sun */
/* one test case problem. line 115 to 125 solved such problem. */
#include<iostream>
#include<vector>
#define MAX_SIZE 10000
using namespace std;
int startPos,endPos;
bool flag;
int MaxSubsequenceSum(const int A[],int N){
	int thisSum,maxSum;
	flag=false;
	startPos=0;
	int tempStart=0;
	endPos=0;
	thisSum=0;
	maxSum=0;
	for(int i=0;i<N;i++){
		thisSum+=A[i];
		if(A[i]>=0){
			flag=true;
		}
		//cout<<"thisSum "<<thisSum<<endl;
		if(thisSum>maxSum){
			 endPos=i;
			 startPos=tempStart;
			 maxSum=thisSum;
		}
		else if(thisSum<=0){
			tempStart=i+1;
			thisSum=0;
		}
	}
	return maxSum;
}
int main(){
	freopen("D:\\in.txt","r",stdin);
	int n,size;
	scanf("%d",&n);
    size=n;	
	int list[MAX_SIZE];
	int temp,i;
	i=0;
	while(n--){
		scanf("%d",&temp);
		list[i]=temp;
		i++;
	}
	int result=MaxSubsequenceSum(list,size);
	if(flag==false){
		cout<<0;
        cout<<" "<<list[0]<<" "<<list[size-1];	
		return 0;
	}
    if(result<=0)
 	{
		for(int i=0;i<size;i++){
			if(list[i]==0){
				result=0;
				startPos=i;
				endPos=i;
				break;
			}
		}
	}
		cout<<result;
	    cout<<" "<<list[startPos]<<" "<<list[endPos];
	return 0;
} 
/* DP solution.. 2016-7-31 by your own */
#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX_SIZE 10001
using namespace std;
typedef struct Node{
	int left;
	int right;
	int value;
}Node;
bool cmp(const Node &a,const Node &b){
	if(a.value!=b.value){
		return a.value>b.value;
	}
	else{
		if(a.left!=b.left) return a.left<b.left;
		else return a.right<b.right;
	}
}
int main(){
	//freopen("D:\\in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	Node temp;
	vector<Node> result_vec;
	vector<int> vec(n);
	/* dp stores the  maximum subsequence sum that contants the last digit */
	int dp[MAX_SIZE];
	for(int i=0;i<n;i++){
		scanf("%d",&vec[i]);
	}
	dp[1]=vec[0];
	temp.left=0;
	temp.right=0;
	temp.value=dp[1];
	int cur_left=0;
	int right;
	result_vec.push_back(temp);
	for(int i=1;i<n;i++){
	  // dp[i+1]=max(dp[i]+vec[i],vec[i]);
	   if(dp[i]+vec[i]>vec[i]){
		   dp[i+1]=dp[i]+vec[i];
	   }
	   else{
		   cur_left=i;
		   dp[i+1]=vec[i];
	   }
	   right=i;
	   temp.left=cur_left;
	   temp.right=right;
	   temp.value=dp[i+1];
	   result_vec.push_back(temp);
	}
	sort(result_vec.begin(),result_vec.end(),cmp);
	vector<Node>::iterator iter=result_vec.begin();
	if(iter->value<0) printf("%d %d %d\n",0,vec[0],vec[n-1]);
	else
	printf("%d %d %d\n",iter->value,vec[iter->left],vec[iter->right]);
	return 0;
}