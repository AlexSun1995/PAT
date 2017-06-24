/* General Palindromic Number patId:1019 */
/* start time: 2016-5-28 14:46 */
/* located in ahu library */
/* submit time:2016-5-28 15:22 */
/* 20/20 Accepted! */
#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
using namespace std;
vector<long int> vecResult;
void printResult(){
	int n=vecResult.size();
	if(n==0){
		cout<<0<<endl;
		return;
	}
	for(int i=n-1;i>0;i--){
		cout<<vecResult[i]<<" ";
	}
	cout<<vecResult[0]<<endl;
}
int main(){
	long int N;
    long int base;
	bool flag=true;
    stack<long int> sta;
    queue<long int> que;	
    cin>>N>>base;
	long int a,b;
	while(N!=0){
		a=N%base;
		//cout<<"N: "<<N<<" a: "<<a<<endl;
		N=N/base;
        sta.push(a);
        que.push(a);
        vecResult.push_back(a);		
	}
	while(!sta.empty()){
        if(sta.top()!=que.front()){
			cout<<"No"<<endl;
			printResult();
			flag=false;
			break;
		}
		sta.pop();
		que.pop();    		
	}
	if(flag){
		cout<<"Yes"<<endl;
		printResult();
	}
    return 0;   	
}  