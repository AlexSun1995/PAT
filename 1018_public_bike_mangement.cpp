/* Public Bike Mangement patID: 1018 *//* starting time: 2016-6-10 17:51 *//* 22/30 learning and AC it 0n 2016-6-11 !! *//* Dijkstra' Alogorithm and Record all the shortest paths *//* and using DFS to find the best result. */#include<vector>#include<iostream>#define MAX_DIS 100000using namespace std;int minSend;int minTakeBack;typedef struct Node{	int id;	int sumDis;	int c;	bool known;}Node;typedef struct Edge{	int id;	int dis;}Edge;vector<Node> vec; vector<vector<int> > allPaths;vector<int> bestPath;vector<int> possibleBest;void initVec(int info[],int size){	for(int i=0;i<=size;i++){		vec[i].id=i;		vec[i].c=info[i];		vec[i].sumDis=MAX_DIS;		vec[i].known=false;	}} int findShortestid(){	vec[0].known=true;    vector<Node>::iterator iter=vec.begin();	int min,minid;	minid=-1;	for(;iter!=vec.end();iter++){		if(iter->known) continue;        else{			min=iter->sumDis;			minid=iter->id;			break;		}			}	for(iter=vec.begin();iter!=vec.end();iter++){		if(!iter->known&&(iter->sumDis)<min){		 	min=iter->sumDis;			minid=iter->id;		}	}	return minid; }  void findBestPath(int Sp,int Cmax){	  int u = Sp;	  possibleBest.push_back(u);	  if(u==0){		    int collect=0;			int send=0;			for(int i=possibleBest.size()-1;i>=0;i--){				int v = possibleBest[i];				if(vec[v].c<Cmax/2){					collect-=(Cmax/2-vec[v].c);				}				else if(vec[v].c>Cmax/2){					collect+=(vec[v].c-Cmax/2);				}				if(collect<0){				   send+=-collect;                   collect=0;				   				} 				}			if(minSend>send){			   minSend=send;			   minTakeBack=collect;               bestPath=possibleBest;			   			}else if(minSend==send){				if(minTakeBack<collect){			        minTakeBack=collect;                    bestPath=possibleBest;									}			}		   return;	   }	  for(int i=0;i<allPaths[u].size();i++){		  findBestPath(allPaths[u][i],Cmax);		  possibleBest.pop_back();     // consider this step, and think why?	  } }  void dijkstra(vector<Edge> graph[]){    vector<Edge>::iterator iter = graph[0].begin();	for(;iter!=graph[0].end();iter++){        vec[iter->id].sumDis=	iter->dis;			allPaths[iter->id].push_back(0);	}	int v,u;	while(true){	  v=findShortestid();	  if(v==-1) break;		  vec[v].known=true;	  vector<Edge>::iterator iter1=graph[v].begin();	  for(;iter1!=graph[v].end();iter1++){		  u=iter1->id;	     if(!vec[u].known&&vec[u].sumDis>vec[v].sumDis+iter1->dis){			vec[u].sumDis=vec[v].sumDis+iter1->dis; 			allPaths[u].clear();            allPaths[u].push_back(v);					 }         else if(!vec[u].known&&vec[u].sumDis==vec[v].sumDis+iter1->dis){			   allPaths[u].push_back(v);		 }		 	  }	}    }int main(){	//freopen("D:\\in.txt","r",stdin);	int Cmax,Ns,Sp,Nr; //max capacity, num of Edges,problem Edge,num of roads.	cin>>Cmax>>Ns>>Sp>>Nr;    allPaths.resize(Ns+1);	vector<Edge> *graph=new vector<Edge>[Ns+1];    vec.resize(Ns+1);	int *info=new int[Ns+1];	int temp;	minSend=minTakeBack=MAX_DIS;	info[0]=Cmax/2;	for(int i=1;i<=Ns;i++){		cin>>temp;		info[i]= temp;	}	initVec(info,Ns);	Edge s;	while(Nr--)	{	  int a,b;	  int dis;      cin>>a>>b;	  cin>>s.dis;	  s.id=b;      graph[a].push_back(s);	  s.id=a;      graph[b].push_back(s); 	}		/* find shortest path */	dijkstra(graph);	/* find the best among all the best paths */	findBestPath(Sp,Cmax);	/* output the result. */	cout<<minSend<<" ";	//vector<int>::iterator iter=bestPath.begin();	for(int i=bestPath.size()-1;i>=0;i--){		if(i!=0){			cout<<bestPath[i]<<"->";		}        else cout<<bestPath[i]<<" ";			}    cout<<minTakeBack<<endl;	     	return 0;}/* ********************************* *//* ********baigui sun CSDN 30/30***** */#include<iostream>  #include<vector>  #include<queue>  #include<stack>  using namespace std;    #define INF 0x6FFFFFFF  int Cmax, n, Sp, m;  typedef struct Edge  {      int v, dis;      Edge(int _v, int _dis):v(_v),dis(_dis){}  }Edge;    typedef struct Node  {      int c, dis;  }Node;  vector<vector<Edge>> edge;  vector<Node> city;  vector<vector<int>> allPath;  vector<bool> visited;    vector<int> bestPath;  int minSend = INF;  int minCollect = INF;  vector<int> possiblePath;  void FindBestPath(int u)  {      possiblePath.push_back(u);      if(u == 0)      {//find the end          int send = 0;          int collect = 0;          for(int i = possiblePath.size()-1; i >= 0; --i)          {              int t = possiblePath[i];              if(city[t].c > Cmax/2)                  collect += city[t].c - Cmax/2;              else if(city[t].c < Cmax/2)              {                  collect -= (Cmax/2-city[t].c);                  if(collect < 0) send -=collect, collect=0;              }          }          if(send < minSend) minSend=send, minCollect=collect, bestPath=possiblePath;          else if(send == minSend && collect < minCollect) minCollect=collect, bestPath=possiblePath;          return;      }      for(int i = 0; i < allPath[u].size(); ++i)      {          FindBestPath(allPath[u][i]);          possiblePath.pop_back();      }  }  int FindMin()  {      int mmin = INF;      int index = -1;      for(int i = 0; i <= n; ++i)      {          if(city[i].dis < mmin && !visited[i])          {              mmin = city[i].dis;              index = i;          }      }      return index;  }  void Dijkstra(int s, int t)  {      allPath.clear();      allPath.resize(n+1);      /*for(int i = 0; i <= n; ++i)         allPath[i].push_back(-1);*/      visited.assign(n+1, false);      for(int i = 0; i <= n; ++i)          city[i].dis = INF;      city[0].dis = 0;      while(true)      {          int u = FindMin();          if(u==-1) return;          visited[u] = true;          for(int i = 0; i < edge[u].size(); ++i)          {              int v = edge[u][i].v;              if(!visited[v])              {                  int dis = edge[u][i].dis;                  if(city[v].dis > city[u].dis+dis)                  {                      allPath[v].clear();                      city[v].dis = city[u].dis+dis;                      allPath[v].push_back(u);                  }                  else if(city[v].dis == city[u].dis+dis)                  {                      allPath[v].push_back(u);                  }              }          }      }    }  int main()  {      scanf("%d%d%d%d",&Cmax,&n,&Sp,&m);      city.clear();      city.resize(n+1);      for(int i = 1; i <= n; ++i)      {          scanf("%d",&city[i].c);          city[0].c = Cmax/2;      }      edge.clear();      edge.resize(n+1);      for(int i = 0; i < m; ++i)      {          int a, b, c;          scanf("%d%d%d",&a,&b,&c);          edge[a].push_back(Edge(b,c));          edge[b].push_back(Edge(a,c));      }            //end of input      //1. using dijkstra find all the possible solution      Dijkstra(0, Sp);      //2. enumerate all possible path and record the best one      FindBestPath(Sp);      //output the best solution      printf("%d 0",minSend);      for(int i = bestPath.size()-2; i >= 0; --i)          printf("->%d",bestPath[i]);      printf(" %d\n", minCollect);      return 0;  }  