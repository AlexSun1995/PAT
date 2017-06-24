/* shortest distance patId:1046 */
/* start time:2016-5-30 11:36 */
/* first submit time:2016-5-30 11:56 17/20 one test point timeout */
/* second try time:2016-5-30 12:11 20/20 Accepted! */
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	//freopen("D:\\in.txt","r",stdin);
	int n,m,start,end;
	cin>>n;
	int *cycle=new int[n+1];
	int *memory=new int[n+1];
	int sum=0;
	memory[1]=0;
	for(int i=1;i<=n;i++){
		cin>>cycle[i];
		sum+=cycle[i];
		if(i>1){
			memory[i]+=memory[i-1]+cycle[i-1];
		}
	}
    cin>>m;
	int thissum;
	int othersum;
	while(m--){
		thissum=othersum=0;
		cin>>start>>end;
		
		// for(int i=min(start,end);i<max(start,end);i++){
			// thissum+=cycle[i];
		// }
		thissum=memory[max(start,end)]-memory[min(start,end)];
		othersum=sum-thissum;
		//cout<<"this sum "<<" start :"<<start<<" end "<<end<<"  "<<thissum<<endl;
		cout<<min(thissum,othersum);
		cout<<endl;
	}
	return 0;
}
/* the useful of memory array can really save time a lot */
/* alex */