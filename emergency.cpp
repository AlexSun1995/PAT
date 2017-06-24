/* Emergency patID:1003 */
/* https://www.patest.cn/contests/pat-a-practise/1003 */
/* start time:2016-5-19 18:49 ahu library */
/* fist submmit time: 2016/5/21 0:27 */
/* partly correct, 10/25 come on! */
/* 2016 5-22 17:37 19/25 come on! */
/* problems:1.data structure build. done */
/* 2.how to record all the shortest paths. */
/* 3.find the smallest unknow vertexs */
/* you've done a good job! have a rest! */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX_Vertex 500
#define INFINITY 100000
using namespace std;
typedef pair<int,int> vertexAndCost;  //pair.first: vertex,pair.second:distance.
typedef int Vertex;
typedef struct _graph{
	bool known;
	int dist;
	vector<vertexAndCost> adjacentVertex;
	vector<Vertex> path;
	int rescueMember;
	bool checked;
}Graph;
vector<Vertex> onShortestWayVertex; 
int numPath;
void initVertex(Graph map[],int size){
    for(int i=0;i<size;i++){
		map[i].known=false;
		map[i].dist=INFINITY;
		map[i].rescueMember=0;
        map[i].checked==false;		
	}
}
// void getPath(Graph map[],Vertex current){
	// vector<Vertex>::iterator result;
	// while(map[current].path!=-1){
		// result=find(onShortestWayVertex.begin(),onShortestWayVertex.end(),map[current].path);
		// if(result==onShortestWayVertex.end()){
			// onShortestWayVertex.push_back(map[current].path);
		// }
		// current=map[current].path;
	// }
// }
/* 这个函数从思想上说没有错误 */
/* 但是要注意的是这个是求的所有最短路径上的所有的点 */
/* 没有审题，题目的意思是要求相同最短路径上救援队员最多的值 */
/* 这个算法保留，但不符合题目要求 */
void findAllAjacaentVertex(Graph map[],int targetCity,int shortestLength){
     vector<Vertex>::iterator iter=map[targetCity].path.begin();
	 numPath=0;
	 queue<Vertex> vertexQuene;
	 for(;iter!=map[targetCity].path.end();iter++){
		 vertexQuene.push(*iter);
		 numPath++;
	 }
	 map[targetCity].checked=true;
	 while(!vertexQuene.empty()){
		 if(!map[vertexQuene.front()].checked){
		   iter=map[vertexQuene.front()].path.begin();
		   if(map[vertexQuene.front()].path.size()>0)
		    numPath+=map[vertexQuene.front()].path.size()-1;
		   for(;iter!=map[vertexQuene.front()].path.end();iter++){
		      vertexQuene.push(*iter);
	       }
           map[vertexQuene.front()].checked=true;
           onShortestWayVertex.push_back(vertexQuene.front());		   
		 }
	     vertexQuene.pop();
	 }
}

Vertex findSmallestCostVertex(Graph map[],int size){
	Vertex min=-1;
	for(int j=0;j<size;j++){
		if(map[j].known==false) min=j;
	}
	for(int i=0;i<size;i++){ 
		//cout<<"index i: "<<i<<"->"<<map[i].dist<<endl;
		if(map[i].known==false){
				if(map[min].dist>map[i].dist) min=i;  
		}
	   
	}
	return min;
}
int findShortestPath(Graph map[],int currentCity,int targetCity,int size,int *numMemberEachCity){
	map[currentCity].dist=0;
	map[currentCity].rescueMember=numMemberEachCity[currentCity];
	Vertex v,w;
	while(true){
	    v=findSmallestCostVertex(map,size);
		//cout<<"find v "<<v<<endl;
		/* if v equals to -1, can not find*/
		if(v==-1){
		  break;
		} 
	    map[v].known=true;
		/* find each w adajacent to v which are unknow */
	    vector<vertexAndCost>::iterator iter=map[v].adjacentVertex.begin();
	    for(;iter!=map[v].adjacentVertex.end();iter++){
            if(!map[iter->first].known){
				if(map[iter->first].dist>map[v].dist+(*iter).second){
					map[iter->first].dist=map[v].dist+(*iter).second;
					map[iter->first].path.clear();
					map[iter->first].path.push_back(v);
					map[iter->first].rescueMember=map[v].rescueMember+numMemberEachCity[iter->first];
				}else if(map[iter->first].dist==map[v].dist+(*iter).second){
					map[iter->first].path.push_back(v);
					if(map[v].rescueMember+numMemberEachCity[iter->first]>map[iter->first].rescueMember)
						map[iter->first].rescueMember=map[v].rescueMember+numMemberEachCity[iter->first];
				}
			}		
     	}	
	}  
	return map[targetCity].dist;
}
int main(){
	freopen("D:\\in.txt","r",stdin);
	Graph map[MAX_Vertex];
	int temp1,temp2,temp3;
	int numCities,numRoads,currentCity,targetCity;
	scanf("%d%d%d%d",&numCities,&numRoads,&currentCity,&targetCity);
    initVertex(map,numCities);  
	int *numMemberEachCity=new int[numCities];
	//cout<<"mark"<<e·ndl;
	for(int i=0;i<numCities;i++){
		scanf("%d",&temp1);
		numMemberEachCity[i]=temp1;
	}
	while(numRoads--){
		scanf("%d%d%d",&temp1,&temp2,&temp3);
		vertexAndCost t1=make_pair(temp2,temp3);
		map[temp1].adjacentVertex.push_back(t1);
		vertexAndCost t2=make_pair(temp1,temp3);
		map[temp2].adjacentVertex.push_back(t2);
	}
	int shortestLength;
	int sumMembers=0;
	shortestLength=findShortestPath(map,currentCity,targetCity,numCities,numMemberEachCity);
	if(shortestLength==0){
		sumMembers=numMemberEachCity[currentCity];
	}else{
	  findAllAjacaentVertex(map,targetCity,shortestLength);
	  onShortestWayVertex.push_back(targetCity);
	  vector<Vertex>::iterator iter=onShortestWayVertex.begin();
	  for(;iter!=onShortestWayVertex.end();iter++){
		sumMembers+=numMemberEachCity[*iter];
      }
	}
	//findAllAjacaentVertex(map,targetCity,shortestLength);
	cout<<numPath<<" "<<map[targetCity].rescueMember;
	return 0;
} 