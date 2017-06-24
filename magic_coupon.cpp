/* Magic coupon patID:1037 */
/* start time: 2016-5-30 */
/* first submmit time: 2016-5-30 17:22 */
/* mainly using stl,19/25 some points timeout */
/*********************************
 * first version 19/25
 * hello STL~~ ^_^
 * Time out *@*
 *********************************/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
	//freopen("D:\\in.txt","r",stdin);
	priority_queue<int> q1;
	priority_queue<int,vector<int>,greater<int> > q2;
	priority_queue<int> q3;
	priority_queue<int,vector<int>,greater<int> > q4;
	int nc,np;
	int temp;
	int total=0;
	int result=0;
	cin>>nc;
	while(nc--){
		cin>>temp;
		q1.push(temp);
		q2.push(temp);
	}
	cin>>np;
	while(np--){
		cin>>temp;
		q3.push(temp);
		q4.push(temp);
	}
	int big1,small1,big2,small2;
	while(!q1.empty()||!q4.empty()){
		result=0;
		big1=q1.top();
		small1=q2.top();
		big2=q3.top();
		small2=q4.top();
		if(big1*big2>small1*small2){
			result+=big1*big2;
			q1.pop();
			q3.pop();
		}else{
			result+=small1*small2;
			q2.pop();
			q4.pop();
		}
		//cout<<"big1 :"<<big1<<" result: "<<result<<endl;
		//cout<<big1<<" "<<big2<<" "<<small1<<" "<<small2<<endl;
		if(result<=0) break;
		else total+=result;
	}
	cout<<total<<endl;
	return 0;
}
/*******************************************
*second version 25/25 Accepted!
*by using std::deque which is a member of C++ stand
*deque allows pop_back and pop_front operate in a 
*quick speed  
*******************************/
#include<iostream>
#include<queue>
#include<vector>	
#include<algorithm>
using namespace std;
int main(){
	//freopen("D:\\in.txt","r",stdin);
	deque<int> v1;
	deque<int> v2;
	int nc,np;
	int temp;
	cin>>nc;
	for(int i=1;i<=nc;i++){
		cin>>temp;
		v1.push_back(temp);
	}
	cin>>np;
	for(int i=1;i<=np;i++){
		cin>>temp;
		v2.push_back(temp);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int result;
	int total=0;
	while(!v1.empty()&&!v2.empty()){
		result=0;
		if(v1.front()*v2.front()>v1.back()*v2.back()){
			result=v1.front()*v2.front();
			v1.pop_front();
			v2.pop_front();
		}else{
			result=v1.back()*v2.back();
			v1.pop_back();
			v2.pop_back();
		}
		if(result<=0) break;
		else total+=result;
	}
	cout<<total<<endl;
	return 0;
}
/***********************************
* third version Baigui sun from CSDN
**********************************/
#include<iostream>  
#include<set>  
  
struct myComp  
{  
    bool operator()(const int& a, const int& b) 
    {  
        return a > b;  
    }  
};  
int main()  
{  
    int nc, np;  
    while(scanf("%d",&nc)!=EOF)  
    {  
        std::multiset<int, myComp>c1, p1;  
        std::multiset<int> c2, p2;//negtive  
        while(nc--)  
        {  
            int tmp;  
            scanf("%d",&tmp);  
            if(tmp>=0) c1.insert(tmp);  
            else c2.insert(tmp);  
        }  
        scanf("%d",&np);  
        while(np--)  
        {  
            int tmp;  
            scanf("%d",&tmp);  
            if(tmp>=0) p1.insert(tmp);  
            else p2.insert(tmp);  
        }  
        //get the max  
        int max = 0;  
        while(!c1.empty() && !p1.empty())  
        {  
            std::multiset<int, myComp>::iterator it1, it2;  
            it1 = c1.begin();  
            it2 = p1.begin();  
            int a = (*it1);  
            int b = (*it2);  
            max += a*b;  
            c1.erase(it1);  
            p1.erase(it2);  
        }  
        while(!c2.empty() && !p2.empty())  
        {  
            std::multiset<int>::iterator it1, it2;  
            it1 = c2.begin();  
            it2 = p2.begin();  
            int a = (*it1);  
            int b = (*it2);  
            max += a*b;  
            c2.erase(it1);  
            p2.erase(it2);  
        }  
        //output  
        printf("%d\n", max);  
    }  
    return 0;  
}  
