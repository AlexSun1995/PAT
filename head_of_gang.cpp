/* head of a gang padId:1034 */
/* in practice of Union-find set */
/*  start time: 2016-5-26 13:30 library ahu*/
/* too many error,reconsider it  */
/* 2016-5-27 20:58 */
/* first submit time: 2016-5-28 11:36 */
/* my version 
/* 30/30 Accepted! */
#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
//struct construct and its initialize;
//wiznote c++ coding file
typedef struct Edge{
	string name;
	bool known;
	int timeLen;
	Edge(string _name,int _timeLen):name(_name),timeLen(_timeLen),known(false){};  //is it a construct?  
}Edge;
typedef struct Node{
   string parent; 
   bool isknown;
}Node;
map<string,Node> people;
void compress(string top,string x){
	if(people[x].parent!=top){
		compress(top,people[x].parent);
		people[x].parent=top;
	}
}
string findSet(string x){
	if(people[x].parent!=x){
		string top=findSet(people[x].parent);
		compress(top,x);
	}
	return people[x].parent;
}
void unionSet(string x,string y){
	string a=findSet(x);
	string b=findSet(y);
	people[a].parent=b;
}
int main(){
	//freopen("D:\\in.txt","r",stdin);
	map<string,vector<Edge> > contactsMap;
	int n,k;//num of phone call and weight threthold
	cin>>n>>k;
	string name1,name2;
	int timeLen;
	//input
	for(int i=0;i<n;i++){
		cin>>name1>>name2>>timeLen;
	    map<string,vector<Edge> >::iterator iter;
		Node node1;
		node1.parent=name1;
		node1.isknown=false;
		people.insert(make_pair(name1,node1));
		node1.parent=name2;
		people.insert(make_pair(name2,node1));
		iter=contactsMap.find(name1);
		vector<Edge> tempVec;
		if(iter!=contactsMap.end()){
		   tempVec.assign(contactsMap[name1].begin(),contactsMap[name1].end());
		   contactsMap.erase(iter);
		}
		tempVec.push_back(Edge(name2,timeLen));
		contactsMap.insert(make_pair(name1,tempVec));	
	}

    map<string,vector<Edge> >::iterator iter=contactsMap.begin();
    for(;iter!=contactsMap.end();iter++){
		vector<Edge> vec=contactsMap[iter->first];
		vector<Edge>::iterator iterVec=vec.begin();
		for(;iterVec!=vec.end();iterVec++){
			unionSet(iter->first,iterVec->name);
		} 
	}
	//test map<string,Node> people ok,accepted,don't forget to erase map 
	// if you wanna update the value of a map.
	/*
	  map<string,Node>::iterator iterTest=people.begin();
	  for(;iterTest!=people.end();iterTest++){
		cout<<"head: "<<iterTest->first<<"  parent: "<<(iterTest->second).parent<<endl;
    	}
	*/
	queue<string> que;
	map<string,Node>::iterator iter2=people.begin();
	map<string,int> result;
	map<string,bool> checked;
	int gangHeadCount=0;
	int timesCount=0;
	int sumPart=0;
	map<string,int> nameTime;
	for(;iter2!=people.end();iter2++){
			//cout<<"ok,we start consider: "<<iter2->first<<endl;
			 que.push(iter2->first); 
			 timesCount=0;
		     while(!que.empty()){	
			    if(checked[que.front()]==true){
				   que.pop();
				   //cout<<"yes,we do"<<endl;
			 	   continue;
			      }else{ 
					//cout<<"yes changed"<<endl;
				    checked[que.front()]=true;
			      }
				//cout<<que.front()<<endl;
				vector<Edge>::iterator iter3=contactsMap[que.front()].begin();
				map<string,int>::iterator tempIter;
                for(;iter3!=contactsMap[que.front()].end();iter3++){
					que.push(iter3->name);
					timesCount+=iter3->timeLen;
					if(nameTime.find(que.front())==nameTime.end())
						nameTime.insert(make_pair(que.front(),0));
					nameTime[que.front()]+=iter3->timeLen;
					//cout<<que.front()<<" plus "<<iter3->timeLen<<endl;
					 if(nameTime.find(iter3->name)==nameTime.end())
						 nameTime.insert(make_pair(iter3->name,0));
					 nameTime[iter3->name]+=iter3->timeLen;
				}			
                que.pop();		
			 }
			  if(timesCount>k&&nameTime.size()>2){
				  //  cout<<"times "<<timesCount<<endl;
					sumPart++;
					map<string,int>::iterator iter4=nameTime.begin();
					int max=iter4->second;
					string maxName=iter4->first;
					for(;iter4!=nameTime.end();iter4++){
						if(iter4->second>max){
							max=iter4->second;
							maxName=iter4->first;
						}			 
					}
					result.insert(make_pair(maxName,nameTime.size()));   
				}	
               nameTime.clear();				
	}
	map<string,int>::iterator iter5=result.begin();
	cout<<sumPart<<endl;
	for(;iter5!=result.end();iter5++){
		cout<<iter5->first<<" "<<iter5->second;
		cout<<endl;
	}
	return 0;
}
/* this code is well worth review and think. */
/* key points */
/* 1.how to store and find a graph node by the string type name? */
    /*
      we use map<string,vector<Edge>> to mark the whole graph
      Edge is a data type we creat which in order to store 
      the  adajacent node and the weight between the two nodes.	  
	*/
/* 2.how to use the Union-find set to mark the linked sub-map? */
    /*
        we use map<string,Node>people to store vertex and its 
		parent info.Node only has a member: parent which to mark 
		one vertex's parent.    		
	*/
/* 3.how to realize the computing algorithm and record the key information? */
    /*      
       for every element in map<string,Node>people,
       every time we get a element e in map<string,Node>people
         starting from e,we execute the BFS() algorithm(of course dfs() is okey)
         label: for que.front() in the queue,we mark it as known first( using the 		 
         map<string,bool> checked data structure)
		 map<string,int> nameTime is a temporary set used for record every vertex's
		 summary weight.
         sub-map
		 each time
         		 
	*/
/***************************************
 *other version: by Baigui Sun From CSDN.
/*************************************/
#include <iostream>  
#include <vector>  
#include <map>  
#include <set>  
#include <string>  
#include <algorithm>  
using namespace std;  
  
typedef struct Node  
{  
    int weight, parent;  
}Node;  
typedef struct Call  
{  
    string a, b;  
    int t;  
}Call;  
typedef struct Gang  
{  
    int head, num, sum, maxw;  
    Gang(){head=-1;num=0;sum=0;maxw=-1;}  
};  
vector<Node> p;//disjoint set  
vector<Call> call;  
map<string, int> name2id;  
map<int, string> id2name;  
set<string> name;  
int n, k;  
int realn;//number of distinct node  
void InitSet()  
{  
    p.resize(realn);  
    for (int i = 0; i < realn; ++i)  
    {  
        p[i].parent = i; p[i].weight = 0;  
    }  
}  
void CompressSet(int top, int x)  
{  
    if (top != p[x].parent)  
    {  
        CompressSet(top, p[x].parent);  
        p[x].parent = top;  
    }  
}  
int FindSet(int x)  
{  
    if (x != p[x].parent)  
    {  
        int top = FindSet(p[x].parent);  
        CompressSet(top, x);  
    }  
    return p[x].parent;  
}  
void UnionSet(int x, int y)  
{  
    int a = FindSet(x);  
    int b = FindSet(y);  
    p[a].parent = b;  
}  
int main()  
{  
    while(scanf("%d%d",&n,&k)!=EOF)  
    {  
        call.resize(n);  
        name.clear();  
        for (int i = 0; i < n; ++i)  
        {  
            cin>>call[i].a; cin>>call[i].b; cin>>call[i].t;  
            name.insert(call[i].a); name.insert(call[i].b);   
        }  
        //get the person number  
        realn = name.size();  
        name2id.clear();  
        id2name.clear();  
        set<string>::iterator it1;  
        int id = 0;  
        for (it1=name.begin(); it1!=name.end(); it1++,++id)  
            name2id[*it1] = id, id2name[id]=*it1;  
        //build disjoint set  
        InitSet();  
        for (int i = 0; i < call.size(); ++i)  
        {  
            int u = name2id[call[i].a]; int v = name2id[call[i].b]; int t = call[i].t;  
            //printf("%d %d %d\n", u, v, t);  
            p[u].weight += t; p[v].weight += t;  
            UnionSet(u, v);  
        }  
        //collect all set  
        map<int,Gang> allSet;//father and weight of set  
        map<int,Gang>::iterator it;  
        for (int i = 0; i < realn; ++i)  
        {  
            int top = FindSet(i);  
            it = allSet.find(top);  
            if (it != allSet.end())  
            {  
                allSet[top].sum += p[i].weight;  
                allSet[top].num++;  
                if (p[i].weight > allSet[top].maxw)  
                {  
                    allSet[top].head = i;  
                    allSet[top].maxw = p[i].weight;  
                }  
                  
            }  
            else  
            {  
                Gang tmp;  
                tmp.head = i; tmp.maxw = p[i].weight;   
                tmp.num = 1;  tmp.sum = p[i].weight;  
                allSet[top] = tmp;  
            }  
        }  
        //threthold gang  
        std::vector<Gang> gang;  
        for (it = allSet.begin(); it!=allSet.end(); it++)  
            if (it->second.sum > k*2 && it->second.num > 2)   
                gang.push_back(it->second);  
        //output  
        vector<pair<string, int>> head;  
        for (int i = 0; i < gang.size(); ++i)  
            head.push_back(make_pair(id2name[gang[i].head],gang[i].num));  
        sort(head.begin(), head.end());  
        printf("%d\n",head.size());  
        for (int i = 0; i < head.size(); ++i)  
            cout<<head[i].first<<" "<<head[i].second<<endl;  
    }  
    return 0;  
}  
