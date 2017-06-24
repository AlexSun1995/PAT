/* PatId:1055 the World's Richerst */
/* starting time:2016-7-17 11:32 AM */
/* Running for PAT! */
/* 21/25 2016-7-17 1:18 pm one case timeout.. */
/* 25/25 Accepted! 2016-7-17 1:22 pm ahu library */
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef struct Richman{
	char name[9];
	int age;
	int wealth;
}Richman;
bool comp1(const Richman &a,const Richman &b){
	if(a.wealth>b.wealth) return true;
   else if(a.wealth==b.wealth){
		 if(a.age<b.age) return true;
		 else if(a.age==b.age){
			int cmp = strcmp(a.name,b.name);
			if(cmp>0) return false;
			else if(cmp<0) return true;
		 }
		 else return false;
	 }
	 else return false;
}
int main(){
// freopen("D:\\in.txt","r",stdin);
  int n,k; //num of people,num of queries
  vector<Richman> vec;
  scanf("%d%d",&n,&k);
    vec.resize(n);
  //cout<<"hello"<<endl;
  for(int i=0;i<n;i++){
	  scanf("%s",&vec[i].name);
	  scanf("%d",&vec[i].age);
	  scanf("%d",&vec[i].wealth);
  }
  sort(vec.begin(),vec.end(),comp1);
  int num,min_age,max_age;
  for(int i=1;i<=k;i++){
	  scanf("%d%d%d",&num,&min_age,&max_age);
	  vector<Richman>::iterator iter;
	  printf("Case #%d:\n",i);
	  int count=0;
	  for(iter=vec.begin();iter!=vec.end()&&count<num;iter++){
		    if(iter->age<=max_age&&iter->age>=min_age&&count<num){
				printf("%s %d %d\n",(*iter).name,iter->age,iter->wealth);
				count++;
			}
	  }
	  if(count==0) printf("None\n");
  }
  return 0;
}