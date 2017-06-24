/* Longest Symmeric String PatId:1040 */
/* 2016-6-9 Ahu Bonan */
/* Accepted! 2016-6-9 18:31 25/25  */
#include<iostream>
#include<stack>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
vector<int> sizeStore;
/* judge whether it is symmeric or not */
void judge(char str[], int left,int right){
	int size = right-left+1;
	bool flag=false;
	while(left<=right){
	   if(str[left]==str[right]){
		   left++;
		   right--;
	   }
       else {
		   flag=true;	   
		   break;
	   }
	}
	if(!flag){
		sizeStore.push_back(size); 
		//cout<<"test "<<size<<endl;
	} 
}
int main(){
	freopen("D:\\in.txt","r",stdin);
	char str[1100];
	gets(str);
	/* I guss this is not the best algorithm.. time wasting */
	for(int i=0;str[i]!='\0';i++){
		char curr_c = str[i];
		//cout<<"curr_c "<<curr_c<<endl;
		for(int j=i+1;str[j]!='\0';j++){
			 if(str[j]==curr_c){
				judge(str,i,j); 
			 }
		}
	}
	sizeStore.push_back(1);
	vector<int>::iterator iter=sizeStore.begin();
	int max=*iter;
	for(;iter!=sizeStore.end();iter++){
	   if((*iter)>max) max=*iter;	
	}
	cout<<max<<endl;
	return 0;
}
