/* count ones patId:1049 */
/* start time:2016-6-1 */
/* "stay young,stay naive" */
/* fitst submit time:2016-6-1 11:27 22/30 timeout */
#include<iostream>
using namespace std;
int sum=0;
void spare(int m){
	int base=10;
	while(m/base!=0){
		if(m%base==1) sum++;
		//cout<<m%base<<" "; 
		m/=10;
	}
	//cout<<m%base<<endl;
	if(m%base==1) sum++;
}
int main(){
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
        spare(i);
	cout<<sum<<endl;
  return 0;   
}
/*************************************
*version 2 using sstream 22/30 timeout
*************************************/
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
   int n;
   int sum=0;
   ostringstream ostream;
   cin>>n;
   for(int i=1;i<=n;i++){
	   ostream<<i;
   }
   string str=ostream.str();
   for(int i=0;i<str.size();i++)
	    if(str[i]=='1') sum++;
	cout<<sum<<endl;
  return 0;   
}
/**********************************
*version 3 baigui Sun from CSDN 30/30
************************************/
#include <iostream>  
  
int Count(int n)  
{  
    int ans = 0;  
    int base = 1;  
    //count "1" in every digit, then sum  
    while (n/base != 0)  
    {  
        int right = n%base;//low digit  
		cout<<"right: "<<right<<endl;
        int left = n/(base*10);//high digit
        cout<<"left: "<<left<<endl;		
        int now = (n/base)%10;//current digit 
        cout<<"now: "<<now<<endl;		
        if (now == 0)//current digit 0, then only determined by high digit  
            ans += left*base;  
        else if(now == 1)//current digit 1, then determined by both high and low digit  
            ans += left*base+right+1;  
        else//current digit > 1   
            ans += (left+1)*base;  
        base *= 10;  
    }  
    return ans;  
}  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        int ans = Count(n);  
        printf("%d\n", ans);  
    }  
    return 0;  
}  