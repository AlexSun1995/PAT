/* product of polynomials patId:1009*/
/* starting time:2016-6-2 14:34 */
/* Accepted! 2016-6-2 16:21 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef struct Node{
	float coe;
	int exp;
}Node;
bool myComp(const Node &a,const Node &b){
	return a.exp>b.exp;
}
int main(){
	freopen("D:\\in.txt","r",stdin);
	int k;
	cin>>k;
	Node temp;
	float c;
	int e;
	vector<Node> vec1;
	vector<Node> vec2;
	vector<Node> result;
	while(k--){
		scanf("%d%f",&e,&c);
		temp.coe=c;
		temp.exp=e;
		vec1.push_back(temp);
	}
	cin>>k;
	while(k--){
		scanf("%d%f",&e,&c);
		temp.coe=c;
		temp.exp=e;
		vec2.push_back(temp);
	}
	/* core algorithm1: multiply */
	vector<Node>::iterator iter1=vec1.begin();
	vector<Node>::iterator iter2;
	for(;iter1!=vec1.end();iter1++){
		for(iter2=vec2.begin();iter2!=vec2.end();iter2++){
			temp.coe=(iter1->coe)*(iter2->coe);
			temp.exp=(iter1->exp)+(iter2->exp);
			result.push_back(temp);
		}
	}
	sort(result.begin(),result.end(),myComp);
	/* core algorithm2: merge */
	vector<Node>::iterator front=result.begin();
	vector<Node>::iterator back=result.begin();
	vector<Node> realResult;
	front++;
	temp.coe=0;
	temp.exp=0;
	while(front!=result.end()){
		if(front->exp!=back->exp){
			while(back!=front){
				temp.coe+=back->coe;
				temp.exp=back->exp;
				back++;
			}
			realResult.push_back(temp);
			temp.coe=0;
			temp.exp=0;
			front++;
		}else{
			front++;
		}
	}
	while(back!=result.end()){
		realResult.push_back(*back);
		back++;
	}
	int cnt=0;
	vector<Node>::iterator i=realResult.begin();
	for(;i!=realResult.end();i++){
		if(abs(i->coe)> 1e-6){
			cnt++;
		}
	}
	i=realResult.begin();
	printf("%d",cnt);
	for(;i!=realResult.end();i++){
		if(abs(i->coe)> 1e-6)
		 printf(" %d %.1f",i->exp,i->coe);
	}
	return 0;
}