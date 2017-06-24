/* pat test exercise */
/* Stack patID:1057  Alex Sun 2016-5-2 Ahu BoNan*/
/* URL:https://www.patest.cn/contests/pat-a-practise/1057  */
/* 2016-5-2 partly right. reason:not quickly */
#include<iostream>
#include<queue>
#include<string>
#include<stack>
#include<vector>
using namespace std; 
class Stack{
	public:
	vector<int> data;
	void push(int t){
		data.push_back(t);
	}
	void pop(){
		data.pop_back();
	}
	int top(){
	    return data.back();	
	}
	bool empty(){
		if(data.empty()) return true;
		else return false;
	}
	int size(){
		return data.size();
	}
};
int main()
{
	
	int commandLines;
    vector<string> commands;
	vector<int> imiStack;
	Stack sta;
	int n;
	int i;
	string command;
	cin>>commandLines;
	getline(cin,command);
	while(commandLines--){
		getline(cin,command);
		commands.push_back(command);
	}
	vector<string>::iterator iter=commands.begin();
	for(;iter!=commands.end();iter++){
		 command=*iter;
     if(command=="Pop"){
		  if(sta.empty()==true) cout<<"Invalid"<<endl;
		  else{    
			 cout<<sta.top()<<endl;
             sta.pop();			 
		  }
		    
	  }else if(command=="PeekMedian"){
		  if(sta.empty()==true) cout<<"Invalid"<<endl;
		  else{
			 if(sta.size()%2==0) n=sta.size()/2;
               else n=(sta.size()+1)/2;
			   i=1;
               priority_queue<int,vector<int>,greater<int> > tempQ(sta.data.begin(),sta.data.end());
			   while(i<n){
				   tempQ.pop();
				   i++;
			   }
			   cout<<tempQ.top()<<endl;
		  } 
	  }else{
	      int num=0;
		  int cnt_int=1;    //jinwei flag
		  int pointer=command.length()-1;
		   while(command[pointer]!=' '){
			  // cout<<"command[pointer] "<<command[pointer]<<endl;
			  num+=cnt_int*(command[pointer]-'0');   //attention: can not cast directely
			  cnt_int*=10;
			  pointer--;
		   } 
		   sta.push(num);
	  }
	}
    return 0;	
}