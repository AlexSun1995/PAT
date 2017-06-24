/* password patId:1035 */
/* start time:2016-6-1 21:00 */
/* c type string and C++ type string */
/* Accepted! 20/20 */
#include<iostream>
#include<vector>
using namespace std;
typedef struct user{
	string id;
	string password;
}user;
int main(){
	//freopen("D:\\in.txt","r",stdin);
	int n,n1;
	cin>>n;
	string id;
	char psw[11];
	vector<user> vec;
	user temp;
	n1=n;
	while(n1--){
		cin>>id;
		scanf("%s",psw);
		bool flag=false;
		for(int i=0;psw[i]!='\0';i++){
			switch(psw[i]){
				case '1': psw[i]='@';flag=true;break;
				case '0': psw[i]='%';flag=true;break;
				case 'l': psw[i]='L';flag=true;break;
				case 'O': psw[i]='o';flag=true;break;
				default: break;
			}
		}
		if(flag){
	     temp.id=id;
		 string str(psw);
		 temp.password=str;
		 vec.push_back(temp);
		}
	}
	vector<user>::iterator iter=vec.begin();
	if(vec.size()==0&&n>1){
		cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
	}else if(vec.size()==0&&n==1){
		cout<<"There is "<<n<<" account and no account is modified"<<endl;
	}else{
		cout<<vec.size()<<endl;
		for(;iter!=vec.end();iter++){
		cout<<iter->id<<" "<<iter->password<<endl;
	   }
	}
	return 0;
}
	