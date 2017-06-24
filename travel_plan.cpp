/* travel plan patId:1030 */
/* start time: 2016-5-29 9:47 ahu library */
/* "programming is an art form." */
/* first submit time: 2016-5-29 11:16 */
/* 30/30 Accepted!great! */
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#define MAX 100000
#define MAX_CITY 500
using namespace std;
typedef struct Node{
	bool known;
	int dis;
	int path;
	int totalCost;
}Node;
stack<int> resultPath;
typedef struct City{
    int id;
    int length;
    int cost;	
}City;
Node initNode(){
	Node n;
	n.dis=MAX;
	n.known=false;
	n.path=-1;
	n.totalCost=0;
	return n;
}
int findShortestUnknown(Node CityInf[],int n){
	int mini=-1;
	int minv;
	for(int i=0;i<n;i++){
		if(!CityInf[i].known){
			mini=i;
			minv=CityInf[i].dis;
			break;
		}
	}
	if(mini!=-1){
      for(int i=mini;i<n;i++){
	     if(!CityInf[i].known){
		   if(CityInf[i].dis<minv){
			   mini=i;
		   }
	    }	
	 }
   }
	
  return mini;
}
void dijkstra(vector<City> cityMap[],int n,int start,Node CityInf[]){
	 int v,u;
	 CityInf[start].dis=0;
	 while(true){
		v=findShortestUnknown(CityInf,n);
	    if(v==-1){
		break;
	    }
	    CityInf[v].known=true;
        vector<City>::iterator iter;
        for(iter=cityMap[v].begin();iter!=cityMap[v].end();iter++){
			if(!CityInf[iter->id].known){
				if(CityInf[iter->id].dis>CityInf[v].dis+iter->length){
					CityInf[iter->id].dis=CityInf[v].dis+iter->length;
					CityInf[iter->id].totalCost=CityInf[v].totalCost+iter->cost;
					CityInf[iter->id].path=v;
				}
				else if(CityInf[iter->id].dis==CityInf[v].dis+iter->length){
					if(CityInf[iter->id].totalCost>CityInf[v].totalCost+iter->cost){
						CityInf[iter->id].totalCost=CityInf[v].totalCost+iter->cost;
						CityInf[iter->id].path=v;
					}
				}
			}
		}		
	 }	 
}
void printResult(Node CityInf[],int n,int des){
	resultPath.push(des);
	int des1=des;
	while(CityInf[des].path!=-1){
		resultPath.push(CityInf[des].path);
		des=CityInf[des].path;
	}
	int shortestLen=CityInf[des1].dis;
	int cost=CityInf[des1].totalCost;
	while(!resultPath.empty()){
		cout<<resultPath.top()<<" ";
		resultPath.pop();
	}
    cout<<shortestLen<<" "<<cost;
 }
int main(){
	freopen("D:\\in.txt","r",stdin);
	vector<City> cityMap[MAX_CITY];
	Node CityInf[MAX_CITY];
    int n,m,s,d;
	int u,v,len,cost;
	City temp;
    cin>>n>>m>>s>>d;
    for(int i=0;i<m;i++){
		cin>>u>>v>>len>>cost;
		temp.id=v;
		temp.length=len;
		temp.cost=cost;
		cityMap[u].push_back(temp);
		temp.id=u;
		temp.length=len;
		temp.cost=cost;
		cityMap[v].push_back(temp);
	}
    //init the cities 
    for(int i=0;i<n;i++){
		CityInf[i]=initNode();
	}	
	dijkstra(cityMap,n,s,CityInf);
	printResult(CityInf,n,d);
	return 0;
}
