/* PAT 1013 battle over cities */
/* baigui sun from csdn */
#include<iostream>  
#include<vector>  
#include<set>  
#include<map>  
#include<queue>  
#include<algorithm>  
#include<string>  
#include<string.h>  
using namespace std;  
  
int n;//number of city  
int m;//number of edge  
int k;//number of query  
typedef struct Edge  
{  
    int v;  
    Edge(int _v):v(_v){};  
}Edge;  
typedef struct Node  
{  
    int parent;  
}Node;  
vector<Node> city;  
void InitSet()  
{  
    city.resize(n);  
    for(int i = 0; i < n; ++i)  
        city[i].parent = i;  
}  
void CompressSet(int top, int x)  
{  
    if(city[x].parent != top)  
    {  
        CompressSet(top, city[x].parent);  
        city[x].parent = top;  
    }  
}  
int FindSet(int x)  
{  
    if(city[x].parent != x)  
    {  
        int top = FindSet(city[x].parent);  
        CompressSet(top, x);  
    }  
    return city[x].parent;  
}  
void UnionSet(int x, int y)  
{  
    int a = FindSet(x);  
    int b = FindSet(y);  
    city[a].parent = b;  
}  
  
int main()  
{  
    //input  
    scanf("%d%d%d",&n,&m,&k);  
    vector<vector<Edge>> edge;  
    edge.resize(n);  
    for(int i = 0; i < m; ++i)  
    {  
        int a, b;  
        scanf("%d%d",&a,&b);  
        a--; b--;  
        edge[a].push_back(Edge(b));  
        edge[b].push_back(Edge(a));  
    }  
    //  
    //query  
    for(int i = 0; i < k; ++i)  
    {  
        int q;  
        scanf("%d",&q);  
        q--;  
        InitSet();  
        for(int u = 0; u < n; ++u)  
        {  
            for(int j = 0; j < edge[u].size(); ++j)  
            {  
                int v = edge[u][j].v;  
                if(u!=q&&v!=q) UnionSet(u, v);  
            }  
        }  
        set<int> parentSet;  
        for(int j = 0; j < n; ++j)  
            //must be care for this, for consistency we must get the root via FindSet function instead of city[j].parent  
            parentSet.insert(FindSet(j));  
        printf("%d\n", parentSet.size()-2);  
    }  
    return 0;  
}  