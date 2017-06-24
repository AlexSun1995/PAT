/* patId:1047 student list for courses */
/* Given a list courses of each students */
/* Output each course's student list */
/* the thinking of algorithm is simple */
/* Using char[] rather than string! */
/* Using printf/scanf rather than cout/cin! */
/* Alex Sun 2016-7-2 Home in Guangde,Anhui  */
/* 25/25 */
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#define MAX_K 2501
#define MAX_N 40001
using namespace std;
typedef struct Student{
	char name[20];
}Student; 
bool cmp(const Student &a,const Student &b){
	return strcmp(a.name,b.name)<0;
}
int main(){
	//freopen("D:\\in.txt","r",stdin);
	int N,K; //num of students, num of courses
	cin>>N>>K;
	char name[20];
    Student temp;	
    vector<int> student_course[MAX_N];
    vector<Student> vec_course[MAX_K];
	for(int i=1;i<=N;i++){
		int size,id;
		scanf("%s",temp.name);
		cin>>size;
		while(size--){
		    scanf("%d",&id);
			student_course[i].push_back(id);
			vec_course[id].push_back(temp);  
		}
	}
	for(int i=1;i<=K;i++){
	   sort(vec_course[i].begin(),vec_course[i].end(),cmp);
		   printf("%d %d\n",i,vec_course[i].size());
	   for(int j=0;j<vec_course[i].size();j++){
		   printf("%s\n",vec_course[i][j].name);
	   }
	}
	return 0;
}
