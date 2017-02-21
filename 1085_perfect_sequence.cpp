// a far more simple one,cause less bugs than before
// this thinking comes from <algorithm notebook page:167>
// 25/25
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>vec;
int n;
int ans=-111;
long long p;
// return the index of an element in the vec
// which vec[index] is the first element meet vec[index]>x;
int bsearch(int pos,long long x){
	 if(vec[n-1]<=x) return n; 
	// long long m = vec[pos] * p;
     int left = pos+1;
	 int right = n-1;
	 int mid;
     while(left<right){
		 mid  = (left + right)/2;
         if(vec[mid]<=x) left = mid + 1;
		 else right = mid;
	 }
	 return left;
}
int main(){
  freopen("/home/alexsun/in.txt","r",stdin);
  scanf("%d%lld",&n,&p);
  vec.resize(n);
  for(int i=0;i<n;i++) scanf("%lld",&vec[i]);
  sort(vec.begin(),vec.end());
  for(int i=0;i<n;i++){
    ans =  max(ans,bsearch(i,(long long)vec[i]*p) - i);
  }
  cout<<ans<<endl;
  return 0;
}
