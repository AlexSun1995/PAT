/* list sorting patID:1028 */
/* key point: struct sorting */
/* "life is like a box of chocolate" */
/* "you never know what you are going to get." */
/* start time:2016-5-30 9:33 */
/* first submit time: 2016-5-30 10:26 11/25 wrong answer&time out */
/* second try time:2016-5-30 10:37 21/25 one point timeout */

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
typedef struct student{
	int id;
	string name;
	int grade;
}student;
    bool compare1(const student& st1,const student &st2){
		return st1.id<st2.id;
	}
	bool compare2(const student& st1,const student &st2){
		if(st1.name==st2.name){
			return st1.id<st2.id;
		}
		else{
			return st1.name<st2.name;
		}	
	}
	bool compare3(const student& st1,const student &st2){
		if(st1.grade==st2.grade){
			return st1.id<st2.id;
		}
		else{
			return st1.grade<st2.grade;
		}	
	}
int main(){
	//freopen("D:\\in.txt","r",stdin);
	int n,c;
	cin>>n>>c;
	student temp;
	int id;
	string name;
	int grade;
	vector<student> info;
	for(int i=0;i<n;i++){
		cin>>id>>name>>grade;
		temp.id=id;
		temp.name=name;
		temp.grade=grade;
		info.push_back(temp);
	}
	switch(c){
		case 1: sort(info.begin(),info.end(),compare1);break;
		case 2: sort(info.begin(),info.end(),compare2);break;
		case 3: sort(info.begin(),info.end(),compare3);break;
	    default: break;
	}
	vector<student>::iterator iter;
	for(iter=info.begin();iter!=info.end();iter++){
		cout<<setfill('0')<<setw(6)<<iter->id;
		cout<<" "<<iter->name<<" "<<iter->grade;
		cout<<endl;
	}
	return 0;
}
/* points to learn: */
/* 1.sort() use the self defined compare funcation */
/* 2.c++ formatted output */
/* time out solution: string compare and copy is a time waste issue in c++ */
/* char[] is a good substitution for string  */
/* baigui sun from CSDN */
#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<string.h>  
  
typedef struct Student  
{  
    int id;  
    char name[20];  
    int g;  
}Student;  
  
int C;  
bool cmp(Student a, Student b)  
{  
    if(C == 1)  
        return a.id < b.id;  
    else if(C == 2)  
    {  
        if( strcmp(a.name, b.name) == 0 )  
            return a.id < b.id;  
        else return strcmp(a.name, b.name)<0;  
    }  
    else if(C == 3)  
    {  
        if(a.g == b.g)  
            return a.id < b.id;  
        else return a.g < b.g;  
    }  
}  
int main()  
{  
    int N;  
    while( scanf("%d%d", &N, &C) != EOF )  
    {  
        std::vector<Student> stuVec(N);  
        for(int i = 0; i < N; ++i)  
            scanf("%d%s%d", &stuVec[i].id, stuVec[i].name, &stuVec[i].g);  
        //sort  
        std::sort(stuVec.begin(), stuVec.end(), cmp);  
        for(int i = 0; i < N; ++i)  
            printf("%06d %s %d\n", stuVec[i].id, stuVec[i].name, stuVec[i].g);  
    }  
    return 0;  
}  