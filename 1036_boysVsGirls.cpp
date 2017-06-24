/* Boys vs. Girls patID:1036*/
/* starting time:2016-6-1 20:03 */
/* "stay young,stay naive" */
/* first submit time:2016-6-1 20:36 */
/* Accepted! 25/25 */
/* the problem is how to define my own comparsion funcation... */
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct student{
	string name;
	char gender;
	string id;
	int grade;	
}student;
bool myComp(const student &a,const student &b){
	return a.grade<b.grade;
}
int main(){
	//freopen("D:\\in.txt","r",stdin);
	int n,n1;
	cin>>n;
	n1=n;
	student temp;
	vector<student> vec;
	while(n1--){
		cin>>temp.name>>temp.gender>>temp.id>>temp.grade;
		vec.push_back(temp);
	}
	sort(vec.begin(),vec.end(),myComp);
	vector<student>::iterator iter1=vec.begin();
	vector<student>::reverse_iterator iter2=vec.rbegin();
	bool findGirl=false;
	bool findBoy=false;
	/* find boy */
	for(;iter1!=vec.end();iter1++){
		if(iter1->gender=='M'){
			findBoy=true;
			break;
		}
	}
	for(;iter2!=vec.rend();iter2++){
		if(iter2->gender=='F'){
			//cout<<"find it--> "<<iter2->name<<endl;
			findGirl=true;
			break;
		}
	}
	if(findBoy&&findGirl){
		cout<<iter2->name<<" "<<iter2->id<<endl;
		cout<<iter1->name<<" "<<iter1->id<<endl;
		cout<<iter2->grade-iter1->grade<<endl;
	}else if(findBoy){
		cout<<"Absent"<<endl;
		cout<<iter1->name<<" "<<iter1->id<<endl;
		cout<<"NA"<<endl;
	}else if(findGirl){
		cout<<iter2->name<<" "<<iter2->id<<endl;
		cout<<"Absent"<<endl;
		cout<<"NA"<<endl;
	}else{
		cout<<"NA"<<endl;
	}
	return 0;
}