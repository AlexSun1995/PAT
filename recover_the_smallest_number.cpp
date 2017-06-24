/* can not work it out,it's a very */
/* classical interview problem */
/* the algotirhm is simple, but you'd better think it over  */
/* and over again. */
#include <iostream>  
#include <string>  
#include <sstream>  
#include <algorithm>  
using namespace std;  
bool compare(const string& str1, const string &str2)  
{  
    string s1=str1+str2;  
    string s2=str2+str1;  
    return s1<s2;  
}  
void ComArrayMin(int num)  
{  
    string *pStrArray=new string[num];  
  
    for(int i=0; i<num; i++)  
    {  
        cin>>pStrArray[i];          
    }  
  
    sort(pStrArray, pStrArray+num, compare);  
  
    string str = "";  
    for(int i = 0; i < num; i++)  
    {  
        str += pStrArray[i];  
    }  
  
    int j = 0;  
    for ( ;j < str.length(); j++)  
    {  
        if (str[j] != '0')  
        {  
            break;  
        }  
    }  
    if (j == str.length())  
    {  
        str = "0";  
    }  
    else  
    {  
        str = str.substr(j, str.length() - j);  
    }  
      
    cout<<str;  
  
    cout<<endl;  
  
    delete[] pStrArray;  
  
}  
  
int main()  
{  
    //freopen("D:\\in.txt","r",stdin);
    int Num;  
    cin>>Num;  
    ComArrayMin(Num);  
    return 0;  
}  