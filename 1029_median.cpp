/* Median patId:1029 */
/* starting time: 2016-6-2 */
/* using STL sort is a silly choose. */
/* usign cin is a silly choose */
/* using the thinking of merge sort */
/* time out 18/25 forget it,biantai... */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	long int n,m,temp,n1,m1;
	vector<long int> vec1;
	vector<long int> vec2;
	scanf("%ld",&n);
	n1=n;
	while(n--){
		scanf("%ld",&temp);
		vec1.push_back(temp);
	}
	scanf("%ld",&m);
	m1=m;
	while(m--){
		scanf("%ld",&temp);
		vec2.push_back(temp);
	}
    vector<long int>::iterator iter1=vec1.begin();
    vector<long int>::iterator iter2=vec2.begin();
	long int pointer=-1;
	long int memory;
	bool flag=false;
	while(iter1!=vec1.end()&&iter2!=vec2.end()){
		if(*iter1<=*iter2){
			memory=*iter1;
			iter1++;
			pointer++;
		}else{
			memory=*iter2;
			iter2++;
			pointer++;
		}
		if(pointer==(n1+m1-1)/2){
			flag=true;
			break;
		}
	}
	if(!flag){
		/*
		while(iter1!=vec1.end()){
			memory=*iter1;
			iter1++;
			pointer++;
			if(pointer==(n1+m1-1)/2){
			flag=true;
			cout<<memory<<endl;
			return 0;
		  }
		}
		*/
		/* the iter2 comes to end first */
		if(iter1!=vec1.end()){
			cout<<vec1[(n1+m1)/2-vec2.size()]<<endl;
			return 0;
		}else{
			cout<<vec2[(n1+m1)/2-vec1.size()]<<endl;
			return 0;
		}
	}
	cout<<memory<<endl;
	return 0;
}