/* patID:1054 the Dominate Color */
#include<iostream>
#include<map>
using namespace std;
int main(){
	freopen("D:\\in.txt","r",stdin);
    map<long int,int> color2Count;
	int m,n;
	int temp;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%ld",&temp);
			map<long int,int>::iterator iter;
			iter=color2Count.find(temp);
			if(iter==color2Count.end()) color2Count.insert(make_pair(temp,0));
			else color2Count[temp]++;
		}
	}
	map<long int,int>::iterator iter=color2Count.begin();
	int max=iter->second;
	long int max_color=iter->first;
	for(;iter!=color2Count.end();iter++){
		if(iter->second>max){
			max_color=iter->first;
			max=iter->second;
		}
	}
	printf("%ld",max_color);
	return 0;
}