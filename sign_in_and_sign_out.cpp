/* sign in and sign out */
/* absolutely correct */
/*  Alex sun 2016-5-17 ahu*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef struct _record{
	string id;
	int sign_in_secs;
	int sign_out_secs;
}record; 
int main(){
	//freopen("D:\\in.txt","r",stdin);
	int numRecords;
	vector<record> info;
	record tempR;
	string tempS;
	int tempSum1;
	int tempSum2;
	int tempH,tempM,tempSec;
	scanf("%d", &numRecords);
	while(numRecords--){
	    cin>>tempS;
		scanf("%d:%d:%d",&tempH,&tempM,&tempSec);
		tempSum1=tempH*60*60+tempM*60+tempSec;
		scanf("%d:%d:%d",&tempH,&tempM,&tempSec);
		tempSum2=tempH*60*60+tempM*60+tempSec;
		tempR.id=tempS;
		tempR.sign_in_secs=tempSum1;
		tempR.sign_out_secs=tempSum2;
		info.push_back(tempR);
	}
	vector<record>::iterator iter;
	int max,min;
	string firstID,lastID;
	iter=info.begin();
	min=(*iter).sign_in_secs;
	max=(*iter).sign_out_secs;
	firstID=(*iter).id;
	lastID=(*iter).id;
	for(;iter!=info.end();iter++){	
		if(min>(*iter).sign_in_secs){
			min=(*iter).sign_in_secs;
			firstID=(*iter).id;
		}
		if(max<(*iter).sign_out_secs){
			max=(*iter).sign_out_secs;
			lastID=(*iter).id;
		}
	}
	cout<<firstID<<" "<<lastID<<endl;
	return 0;
}