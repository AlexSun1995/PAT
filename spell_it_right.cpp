/* spell it right! */
/* absolutely correct */
/* 2016 5-17 */
#include<iostream>
#include<string>
#include<sstream>
#define MAX 100
using namespace std;
int main(){
	 string num;
	 cin>>num;
	 int sum=0;
	 for(size_t t=0;t!=num.length();t++){
		sum+=(num[t]-'0'); 
	 }
	std::stringstream ss;
    string str;
    ss<<sum;
    ss>>str;
	//cout<<str<<endl;
	for(size_t t=0;t!=str.length();t++){
		switch(str[t]){
			case '0': cout<<"zero"; break;
			case '1': cout<<"one"; break;
			case '2': cout<<"two"; break;
			case '3': cout<<"three"; break;
			case '4': cout<<"four"; break;
			case '5': cout<<"five"; break;
			case '6': cout<<"six"; break;
			case '7': cout<<"seven"; break;
			case '8': cout<<"eight"; break;
			case '9': cout<<"nine"; break;
			default:break;
		}
		if(t!=str.length()-1) cout<<' ';
	}
	return 0;
}