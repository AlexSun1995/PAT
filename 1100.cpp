/* pat 1100  Mars Numbers (20) *//* starting at 2016-8-12 8:31 am*//* 14/20 c/c++ string review... disgarting problem... *//* 20/20 C++ stringstream is more safe than the C sscanf.. */#include<iostream>#include<vector>#include<string>#include<stack>#include<cstdio>#include<map>#include<sstream>using namespace std;string mars1[]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};string mars2[]={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};map<string,int> map1;map<string,int> map2;void transform(string str){	string t=str;	int num;	stringstream ss(str);	if(isdigit(t[0])){		//sscanf(t,"%d",&num);		ss>>num;		if(num<13&&num>=0) cout<<mars1[num%13]<<endl;		else{			cout<<mars2[(num/13)-1];			if(num%13!=0)			cout<<" "<<mars1[num%13]<<endl;		    else cout<<endl;		}	}	else{		// char t_first[4];		// char t_second[4];		// sscanf(t,"%s %s",t_first,t_second);		string fir,temp;		string sec;		vector<string> numVec;		while(1){			ss>>temp;			if(ss.fail()) break;			numVec.push_back(temp);		}		if(numVec.size()<2){			fir=numVec[0];			map<string,int>::iterator iter;			iter=map1.find(fir);			if(iter==map1.end()) cout<<(map2[fir]+1)*13<<endl;			else cout<<map1[fir]<<endl;		}		else{			fir=numVec[0];			sec=numVec[1];			int sum;			sum=map1[sec]+(map2[fir]+1)*13;			cout<<sum<<endl;		}	}}int main(){	freopen("D:\\in.txt","r",stdin);	int n;	scanf("%d\n",&n);	string str;	for(int i=0;i<13;i++) map1.insert(make_pair(mars1[i],i));	for(int i=0;i<12;i++) map2.insert(make_pair(mars2[i],i));	while(n--){		getline(cin,str);	    transform(str);	}	return 0;}