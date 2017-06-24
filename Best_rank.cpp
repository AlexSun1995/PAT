/* The Best Rank patID:1012 */
/* start time:2016/5/25 14:35 */
/* library,AHU */
/* first submit time: 2016/5/25 17:32 */
/* almost correct 23/25 */
/* points:map and set, sort and structure sort */
/* a lot to learn... just waiting for you... */
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<fstream>
#define MAX_NUM 2000
using namespace std;
typedef struct _grade{
	string id;
	int score;
}Grade;
typedef struct _rank{
	int rank;
    int weight;	
}wRank;
bool compare(const Grade &a,const Grade &b ){
	return a.score>b.score;
};
bool compare1(const wRank &a,const wRank &b){
	if(a.rank==b.rank){
		return a.weight>b.weight;
	}else{
		return a.rank<b.rank;
	}
}
void printBestRank(int rc,int rm,int re,int ra){
     vector<wRank> vec;
	 wRank temp;
	 temp.rank=rc;
	 temp.weight=3;
	 vec.push_back(temp);
     temp.rank=rm;
	 temp.weight=2;
	 vec.push_back(temp);
	 temp.rank=re;
	 temp.weight=1;
	 vec.push_back(temp);
	 temp.rank=ra;
	 temp.weight=4;
	 vec.push_back(temp);
     sort(vec.begin(),vec.end(),compare1);
	 cout<<vec.front().rank<<" ";
     switch(vec.front().weight){
		 case 1: cout<<"E";break;
		 case 2: cout<<"M";break;
		 case 3: cout<<"C";break;
		 case 4: cout<<"A";break;
	 }
   cout<<endl;	 
}
int main(){
	//freopen("D:\\in.txt","r",stdin);
	int n,m;
	string id;
	int c,math,eng,ave;
	cin>>n>>m;                //can we use scanf("%s",s) while s is a string type?
	map<string,int> m_c;
	map<string,int> m_math;
	map<string,int> m_eng;
	map<string,int> m_ave;
    vector<Grade> score_c;
	vector<Grade> score_m;
	vector<Grade> score_e;
	vector<Grade> score_a;
	Grade temp;
	for(int i=1;i<=n;i++){
       cin>>id>>c>>math>>eng;
	   temp.id=id;
       temp.score=c;
       score_c.push_back(temp);
       temp.score=math;
       score_m.push_back(temp);	 
       temp.score=eng;
       score_e.push_back(temp);
	   ave=(c+math+eng)/3;
       temp.score=ave;
       score_a.push_back(temp);	   
	}
	sort(score_c.begin(),score_c.end(),compare);
	sort(score_m.begin(),score_m.end(),compare);
	sort(score_e.begin(),score_e.end(),compare);
	sort(score_a.begin(),score_a.end(),compare);
    vector<Grade>::iterator iter;
	int i=1;
	for(iter=score_c.begin();iter!=score_c.end();iter++){
		m_c.insert(make_pair(iter->id,i));
		i++;
	}
	i=1;
	for(iter=score_m.begin();iter!=score_m.end();iter++){
		m_math.insert(make_pair(iter->id,i));
		i++;
	}
	i=1;
	for(iter=score_e.begin();iter!=score_e.end();iter++){
		m_eng.insert(make_pair(iter->id,i));
		i++;
	}
	i=1;
	for(iter=score_a.begin();iter!=score_a.end();iter++){
		m_ave.insert(make_pair(iter->id,i));
		i++;
	}
	map<string,int>::iterator iter_mc;
	map<string,int>::iterator iter_mm;
	map<string,int>::iterator iter_me;
	map<string,int>::iterator iter_ma;
	for(int i=0;i<m;i++){
		cin>>id;
		iter_ma=m_math.find(id);
		if(iter_ma==m_math.end()){
			cout<<"N/A"<<endl;
			continue;
		}else{
			iter_mc=m_c.find(id);
			iter_mm=m_math.find(id);
			iter_me=m_eng.find(id);
			iter_ma=m_ave.find(id);
			printBestRank(iter_mc->second,iter_mm->second,iter_me->second,iter_ma->second);
		}
	}
   return 0; 
}
/* baigui Sun from csdn */
/* absulutely correct */
/* indeed better than yours */
/* 
#include<iostream>  
#include<vector>  
#include<set>  
#include<map>  
#include<queue>  
#include<algorithm>  
#include<string>  
#include<string.h>  
using namespace std;  
int n;//student  
int m;//query  
typedef struct Node  
{  
    string name;  
    int grade[4];  
    int bestRank;  
    int bestGrade;  
}Node;  
typedef struct SortNode  
{  
    int g, idx, rank;  
    bool operator>(const SortNode& orh)const  
    {  
        return g>orh.g;  
    }  
}SortNode;  
char CharTable[4]={'A','C','M','E'};    // _this sequence is very important
#define INF 0x6FFFFFFF  
int main()  
{  
    //input  
    scanf("%d%d",&n,&m);  
    vector<Node> stu(n);//student  
    map<string, int> stuMap;//for query  
    for(int i = 0; i < n; ++i)  
    {  
        cin>>stu[i].name;  
        scanf("%d%d%d", &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);  
        stu[i].grade[0] = stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3];  
        stu[i].bestRank = INF;  
        stuMap[stu[i].name] = i;  
    }  
    //  
    for(int i = 0; i < 4; ++i)//for every record  
    {  
        vector<SortNode> sortNode(n);  
        for(int j = 0; j < n; ++j)  
        {  
            sortNode[j].g = stu[j].grade[i];  
            sortNode[j].idx = j;  
        }  
        sort(sortNode.begin(), sortNode.end(), greater<SortNode>());  
        //process the same grade case  
        int nowGrade = INF;          //what's nowGrade used for? by myself
        int nowRank = 0;  
        for(int j = 0; j < n; ++j)  
        {  
            if(sortNode[j].g == nowGrade)  
                sortNode[j].rank = nowRank;  
            else  
            {  
                sortNode[j].rank = j;  
                nowRank = j;  
                nowGrade = sortNode[j].g;  
            }  
        }  
        //then compare to select the best rank  
        for(int j = 0; j < n; ++j)  
        {  
            int idx = sortNode[j].idx;  
            int rank = sortNode[j].rank;  
            if(stu[idx].bestRank > rank)  
                stu[idx].bestRank = rank, stu[idx].bestGrade = i;  
        }  
    }  
  
    //query  
    for(int i = 0; i < m; ++i)  
    {  
        string name;  
        cin>>name;  
        map<string, int>::iterator it = stuMap.find(name);  
        if(it!=stuMap.end())  
        {  
            int idx = it->second;  
            printf("%d %c\n", stu[idx].bestRank+1, CharTable[stu[idx].bestGrade]);  
        }  
        else printf("N/A\n");  
    }  
    return 0;  
}  
 */