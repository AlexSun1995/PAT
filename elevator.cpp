/* Elevator PAT ID:1008*/
/* https://www.patest.cn/contests/pat-a-practise/1008 */
/* start time:2016-5-19 15:43 */
/* finish time:2016-5-19 16:59 */
/* nothing to say, but the bug is it can stay at the same floor for */
/* more than one times. */
#include<iostream>
#include<queue>
using namespace std;
int compute(int interval){
	//cout<<"interval "<<interval<<endl;
	if(interval>0){
	   return interval*6+5;
	}else if(interval<0){
		return interval*(-4)+5;
	}else{
		return 5;
	}
}
int main(){
	queue<int> que;
	int n;
	int temp;
	bool firstTime;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&temp);
		que.push(temp);
	}
	firstTime=true;
    int lastPos;
	int interval;
	long int sum=0;
	while(!que.empty()){
		if(firstTime){
			firstTime=false;
			interval=que.front()-0;
			sum+=compute(interval);
			//cout<<"sum: "<<sum<<endl;
			lastPos=que.front();
			que.pop();
		}else{
			interval=que.front()-lastPos;
		    sum+=compute(interval);
		    lastPos=que.front();
		    que.pop();
		}	
	}
	printf("%d\n",sum);
	return 0;
}