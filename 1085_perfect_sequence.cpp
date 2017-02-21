// pat 1085,perfect sequence
// this version got 24/5 using b-search...
// still got no idea.. 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>vec;
int n;
int ans=-111;
long long p;
// search the element satisify M<vec[pos]*p,where M is as 
// large as possible from index start to n-1 in vec
// and return (index of M) - pos + 1
int bsearch(int pos,int start){
    if(start>=n) return -111;
	int left = start;
	int m = vec[pos];
	int right = n-1;
	int mid  = left + (right - left)/2;
	while(true){
		mid  = left +(right - left)/2;
		if(vec[mid]<=(long long)m*p&&mid+1<=right&&vec[mid+1]>(long long)m*p){
           break; 
		}
		else if(vec[mid]<=(long long)m*p&&mid+1>right){
			break;
		}
		else if(vec[mid]<=(long long)m*p){
            left = mid + 1;
		}
		else if(vec[mid]>(long long)m*p){
			right = mid - 1;
		}
	}
	return mid - pos + 1;
}
int main(){
  freopen("/home/alexsun/in.txt","r",stdin);
  scanf("%d%lld",&n,&p);
  vec.resize(n);
  for(int i=0;i<n;i++) scanf("%lld",&vec[i]);
  sort(vec.begin(),vec.end());
  for(int i=0;i<n;i++){
    ans =  max(ans,bsearch(i,i+1));
  }
  cout<<ans<<endl;
  return 0;
}
