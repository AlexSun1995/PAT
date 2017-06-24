/* To fill or not fill patId:1033*/
/* start time; 2016-5-31 */
/* in practice of Greedy Algorithm */
/* first submit time: 2016-5-31 21:24 */
/* Accepted! 25/25 but still many unclear... */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct station{
	float dis;
	float price;
}station;
bool compDis(const station &a,const station &b){
	return a.dis<b.dis;
}
int main(){
	//freopen("D:\\in.txt","r",stdin);
	//tank capacity,distance,distance per unit gas,number of station
	float c,d,a;
    int n,n1;
	vector<station> vec;
    cin>>c>>d>>a>>n;
    station temp;
	n1=n;
    while(n1--){
	  cin>>temp.price>>temp.dis;
	  vec.push_back(temp);
	}
	//assume the destination as a station.
	sort(vec.begin(),vec.end(),compDis);
	temp.dis=d;
	temp.price=0;
	vec.push_back(temp);
	float disCount=0;
	int i=0;
	float max_dis=c*a;
	float sumPrice=0;
	float currentGas=0;
	bool reachable=true;
	while(reachable){
		if(vec[0].dis!=0){
			reachable=false;
			break;
		}
		if(disCount>=d){
			break;
		}
		for(int j=i+1;j<=vec.size()-1;j++){
		//if the next station which within the max_dis,and it's cheaper
		//precisely go there
		 if(vec[j].dis-vec[i].dis<=max_dis&&vec[j].price<=vec[i].price){
           //just go there
           disCount+=vec[j].dis-vec[i].dis;
           sumPrice+=((vec[j].dis-vec[i].dis)/a-currentGas)*vec[i].price;
		   //cause we precisely go there,after we 
		   //go there, the tank will be empty.
		   currentGas=0;
           i=j;
           break;		   
		  }
		  //if the next cheaper station is far from reach
		  //full up the tank and
		  //choose the cheapest station within the max_dis and go there.
		  else if(vec[j].dis-vec[i].dis>max_dis){
			 if(j-i==1){
				 //can not reach;
				 //full up the tank.
				 currentGas=c;
				 reachable=false;
				 break;
			 }
			 else{
				  int posi=i+1;
				  int posj=j-1;
				  float minprice=vec[posi].price;
				  int minpos=posi;
				  for(;posi<=posj;posi++){
					  if(vec[posi].price<minprice){
						  minprice=vec[posi].price;
						  minpos=posi;
					  } 
				  }
				  //ok,minpos is the next destination we'll go
				  //and we will full up the tank
				disCount+=vec[minpos].dis-vec[i].dis;
				//cout<<"&&&&&&&disCount: "<<disCount<<endl;
				 sumPrice+=(c-currentGas)*vec[i].price;
				 //cout<<"&&&&&&&sumPrice: "<<sumPrice<<endl;
				currentGas=c-(vec[minpos].dis-vec[i].dis)/a;
				i=minpos;
				break;
			 }
		  }
		}
	}
	if(reachable)
	   printf("%.2f",sumPrice);
    else {
		cout<<"The maximum travel distance = ";
		printf("%.2f",disCount+currentGas*a);
	}
	return 0;
}
/********************************************
 * version 2  from nowCode blog.
 * URL:http://www.nowcoder.com/discuss/398?pos=55&type=8&order=1
 ********************************************/
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;
const double eps = 1.e-8;
pair<double, double> g[505];
deque<pair<double,double> >  q;
int main() {
int n;
freopen("D:\\in.txt","r",stdin);
double tank, dis, avg;
    scanf("%lf%lf%lf%d",&tank, &dis, &avg, &n);
    for (int i = 0; i < n; ++i){
        scanf("%lf%lf",&g[i].second, &g[i].first);
    }
    g[n++] = make_pair(dis, 0.);
    sort(g, g + n);
    double cost = 0., now = 0., oil = 0.;
    for (int i = 0; (i < n) && (now + eps <= dis); ++i){
        double d = g[i].first - now;
        while ((!q.empty()) && (d >= eps)) {
            double need = d / avg;   // gas amount.
            if (q.front().second < need + eps) {
                double temp = q.front().second * avg;
                now += temp;
                cost += q.front().second * q.front().first;
                oil -= q.front().second;
                d -= temp;
                q.pop_front();
            }
            else {
                now += d;
                cost += need * q.front().first;
                q.front().second -= need;
                oil -= need;
                d = 0.;
            }
        }
        if (d >= eps) {
            break;
        }
        while ((!q.empty()) && (q.back().first >= g[i].second + eps)) {
            oil -= q.back().second;
            q.pop_back();
        }
        if (oil + eps <= tank) {
            q.push_back(make_pair(g[i].second, tank - oil));
            oil = tank;
        }
    }
    if (now + eps > dis) {    
        printf("%.2lf\n",cost);
    }
    else {
        printf("The maximum travel distance = %.2lf\n",now);
    }
    return 0;
}
/***********************************
 *version 3, baigui sun from CSDN
 ***********************************/
#include<iostream>  
#include<vector>  
#include<algorithm>  
  
typedef struct Station  
{  
    double dis;  
    double price;  
    bool operator<(const Station& other) const  
    {  
        return dis < other.dis;  
    }  
}Station;  
  
double unit_gas;  
int FindNeatestCheaperStation(int i, double gas, std::vector<Station>& s)  
{  
    int num = s.size();  
    int min_index = i;  
    for(int j = i+1; j < num && s[j].dis-s[i].dis <= gas*unit_gas; ++j)  
    {  
        if(s[j].price < s[min_index].price)  
        {  
            min_index = j;  
            break;  
        }  
    }  
    return min_index;  
}  
  
int GetFastestStation(int i, double gas, std::vector<Station>& s)  
{  
    int num = s.size();  
    int max_index = i;  
    for(int j = i+1; j < num && s[j].dis-s[i].dis <= gas*unit_gas; ++j)  
    {  
        max_index = j;  
    }  
    return max_index;  
}  
  
int main()  
{  
    double max_gas, total_dis;  
    int n;  
    while(scanf("%lf%lf%lf%d",&max_gas,&total_dis,&unit_gas,&n)!=EOF)  
    {  
        std::vector<Station> sVec(n);  
        for(int i = 0; i < n; ++i)  
            scanf("%lf %lf",&sVec[i].price,&sVec[i].dis);  
        //sort station by distance  
        std::sort(sVec.begin(), sVec.end());  
        Station vir;  
        vir.dis = total_dis;//add destination as a virtual station in the end  
        sVec.push_back(vir);  
        //algorithm core  
        if(n==0 || sVec[0].dis > 0)//special case  
            printf("The maximum travel distance = 0.00\n");  
        else//greedy now  
        {  
            double remain_gas = 0.0;  
            double cur_money = 0.0;  
            int i;  
            for(i = 0; i < n; )  
            {  
                int index;  
                //1. using remain gas find nearest cheaper station  
                index = FindNeatestCheaperStation(i, remain_gas, sVec);  
                if(index != i)//find a station else  
                {//get there  
                    remain_gas -= (sVec[index].dis-sVec[i].dis)/unit_gas;  
                    i = index;  
                    continue;  
                }  
                //2. using max_gas find nearest cheaper station  
                index = FindNeatestCheaperStation(i, max_gas, sVec);  
                if(index != i)//find a station else  
                {//get there  
                    cur_money += ((sVec[index].dis-sVec[i].dis)/unit_gas-remain_gas)*sVec[i].price;  
                    remain_gas = 0.0;  
                    i = index;  
                    continue;  
                }  
                //3. get the max_gas and go as far as possible  
                index = GetFastestStation(i, max_gas, sVec);  
                if(index != i)  
                {//can get some where  
                    cur_money += (max_gas-remain_gas)*sVec[i].price;  
                    remain_gas = max_gas-(sVec[index].dis-sVec[i].dis)/unit_gas;  
                    i = index;  
                    continue;  
                }  
                else   
                {  
                    printf("The maximum travel distance = %.2lf\n", sVec[i].dis+max_gas*unit_gas);  
                    break;  
                }  
            }//end of greedy  
            if(i == n) printf("%.2lf\n", cur_money);  
        }  
          
    }  
    return 0;   
}  