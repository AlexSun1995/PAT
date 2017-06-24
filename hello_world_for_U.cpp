/* Hello World for U! patID:1031 */
/* start time:2016-5-29 12:48 */
/* Accepted! 20/20 2016-5-29 13:37 */
#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char str[100];
	scanf("%s",str);
	int n=strlen(str);
	int n1,n2,n3;
	for(n2 = 3; n2 <= n; ++n2)  
        {  
            int temp = n+2-n2;  
            if(temp%2 != 0)  
                continue;  
            n1 = temp/2;  
            if(n1 <= n2)  
                break;  
        }
		n3=n1;
    //cout<<n<<" "<<n1<<" "<<n2<<" "<<n3<<endl;	
    int space=n2-2;
	for(int i=0;i<n1-1;i++){
		cout<<str[i];
		for(int j=1;j<=space;j++) cout<<" ";
		cout<<str[n-1-i];
		cout<<endl;
	}
	for(int i=n1-1;i<=n1+n2-2;i++)
		 cout<<str[i];
	
	return 0;
}