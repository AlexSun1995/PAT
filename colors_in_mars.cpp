/* colors in Mars PatId:1027*/
/* starting time:2016-6-2 13:54 */
/* Accepted! time:2016-6-2 14:18 */
#include<iostream>
#include<stack>
using namespace std;
void transfer(int color){
	stack<char> sta;
	const int base=13;
	int rem;
	if(color==0){
		printf("00");
		return;
	}
	while(color!=0){
		rem=color%base;
		color/=base;
		switch(rem){
			case 10:sta.push('A');break;
			case 11:sta.push('B');break;
			case 12:sta.push('C');break;
			default:sta.push(rem+'0');break;
		}
	}
	if(sta.size()==1) printf("0%c",sta.top());
	else{
		printf("%c",sta.top());
		sta.pop();
		printf("%c",sta.top());
	}
}
int main(){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	printf("#");
	transfer(r);
	transfer(g);
	transfer(b);
	printf("\n");
	return 0;
}
/* Baigui sun from CSDN */
#include<iostream>  
#include<vector>  
char g_CharTable[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};  
  
void OutPutIntVector(const std::vector<int>& a)  
{  
    int size = (int)a.size();  
    for(int i = 0; i < size; ++i)  
    {  
        printf("%c", g_CharTable[a[i]]);  
    }  
    printf("\n");  
}  
void Convert2MarsColor(int r, int g, int b, std::vector<int>& color)  
{  
    color.assign(6, 0);  
    color[1] = r%13;  
    color[0] = r/13;  
    color[3] = g%13;  
    color[2] = g/13;  
    color[5] = b%13;  
    color[4] = b/13;  
}  
int main()  
{  
    int r, g, b;  
    while(scanf("%d%d%d", &r, &g, &b) != EOF)  
    {  
        std::vector<int> color;  
        Convert2MarsColor(r, g, b, color);  
        printf("#");  
        OutPutIntVector(color);  
    }  
    return 0;  
} 