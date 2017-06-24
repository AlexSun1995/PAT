/* 1091. Acute Stroke (30) */
/* bfs and count 21/30 first submit */
/* there must be some problem with your understanding  */
/* acturely,the meaning is to bfs a 3-dimension area */
/* but you just do the 2-dimension */
/* restart.. */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#define MAX_M 1290
#define MAX_N 130
using namespace std;
int a[MAX_M][MAX_N];
bool visited[MAX_M][MAX_N];
int m,n,l,t;
void initMark()
{
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			visited[i][j]=false;
		}
}
int bfs(int i,int j)
{
	//cout<<"bfs"<<endl;
	int cnt=0;
	queue<pair<int,int> > que;
	que.push(make_pair(i,j));
	int dir[3]={-1,0,1};
	int cur_i,cur_j;
	while(!que.empty())
	{
		cur_i=que.front().first;
		cur_j=que.front().second;
		for(int x=0;x<3;x++)
		{
			for(int y=0;y<3;y++)
			{
				if(!visited[cur_i+dir[x]][cur_j+dir[y]]&&cur_i+dir[x]>=0&&cur_j+dir[y]>=0&&cur_i+dir[x]<m&&cur_j+dir[y]<n&&a[cur_i+dir[x]][cur_j+dir[y]]==1)
				{
					visited[cur_i+dir[x]][cur_j+dir[y]]=true;
				    cnt++;
					que.push(make_pair(cur_i+dir[x],cur_j+dir[y]));
					//cout<<"push "<<cur_i+dir[x]<<cur_j+dir[y]<<endl;
				}	
			}
		}
		que.pop();
	}
	if(cnt<t) cnt=0;
    return cnt;
}
int main(){
	freopen("D:\\in.txt","r",stdin);	
    scanf("%d%d%d%d",&m,&n,&l,&t);
	int total=0;
	int cnt=0;
	while(l--){
	    initMark();
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
	          scanf("%d",&a[i][j]);
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(!visited[i][j]&&a[i][j]==1)
				{
					cnt+=bfs(i,j);
				}
			}
		}
		//cout<<"test: "<<cnt<<endl;
		total+=cnt;
		cnt=0;
	}
	printf("%d\n",total);
	return 0;
}
/* *************************************** */
/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
/* 1091. Acute Stroke (30) */
/* 3-demison version 30/30 Accepted! */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#define MAX_M 1290
#define MAX_N 130
#define MAX_L 61
using namespace std;
int a[MAX_L][MAX_M][MAX_N];
bool visited[MAX_L][MAX_M][MAX_N];
int m,n,l,t;
typedef struct Node{
	int k;
	int i;
	int j;
}Node;
Node getNode(int x,int y,int z){
	Node temp;
	temp.k=x;
	temp.i=y;
	temp.j=z;
	return temp;
}
void initMark()
{
	for(int i=0;i<l;i++)
		for(int j=0;j<m;j++)
		   for(int k=0;k<n;k++)
			visited[i][j][k]=false;
}
int bfs(int k,int i,int j)
{
	//cout<<"bfs"<<endl;
	int cnt=0;
	queue<Node> que;
	que.push(getNode(k,i,j));
	int cur_k,cur_i,cur_j;
	int dir[]={-1,0,1};
	while(!que.empty())
	{
		cur_k=que.front().k;
	    cur_i=que.front().i;
	    cur_j=que.front().j;
		/* 4 connected area in a plane */
		for(int i=0;i<3;i++)
		{
		    if(cur_i+dir[i]<m&&cur_i+dir[i]>=0&&a[cur_k][cur_i+dir[i]][cur_j]==1)
			{
				if(!visited[cur_k][cur_i+dir[i]][cur_j])
				{
				cnt++;
				visited[cur_k][cur_i+dir[i]][cur_j]=true;
                que.push(getNode(cur_k,cur_i+dir[i],cur_j));				
				}
		    }
			if(cur_j+dir[i]<n&&cur_j+dir[i]>=0&&a[cur_k][cur_i][cur_j+dir[i]]==1)
			{
				if(!visited[cur_k][cur_i][cur_j+dir[i]])
				{
				cnt++;
				visited[cur_k][cur_i][cur_j+dir[i]]=true;
                que.push(getNode(cur_k,cur_i,cur_j+dir[i]));				
				}
		    }
		}
	    if(cur_k+1<l&&!visited[cur_k+1][cur_i][cur_j]&&a[cur_k+1][cur_i][cur_j]==1)
		{
			cnt++;
			visited[cur_k+1][cur_i][cur_j]=true;
			que.push(getNode(cur_k+1,cur_i,cur_j));
		}
		if(cur_k-1>=0&&!visited[cur_k-1][cur_i][cur_j]&&a[cur_k-1][cur_i][cur_j]==1)
		{
			cnt++;
			visited[cur_k-1][cur_i][cur_j]=true;
			que.push(getNode(cur_k-1,cur_i,cur_j));
		}
		que.pop();
	}
	if(cnt<t) cnt=0;
	//printf("this is cnt: %d\n",cnt);
    return cnt;
}
int main(){
	freopen("D:\\in.txt","r",stdin);	
    scanf("%d%d%d%d",&m,&n,&l,&t);
	int total=0;
	int cnt=0;
	initMark();
	for(int k=0;k<l;k++)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
	          scanf("%d",&a[k][i][j]);
			}
		}
	}
	for(int k=0;k<l;k++)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
	          if(!visited[k][i][j]&&a[k][i][j]==1) 
			  {
				cnt+=bfs(k,i,j);  
			  }
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}